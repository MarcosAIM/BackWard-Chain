#include "Engine.h"
#include<iostream>
Engine::Engine(std::map<std::string, std::string> variable_list,
               std::map<std::string, std::string> conclusion_list,
               std::map<int, std::string> knowledge_base,
               std::map<std::string, std::queue<int> > con_ls,
               std::vector<std::string> clause_variable_list,
               std::vector<std::string> clause_conditions_list
              ){
    this->var_list = VariableList(variable_list,conclusion_list);
    this->knowlg_base= KnowledgeBase(knowledge_base);
    this->con_list= ConclusionList(con_ls);
    this->clause_var_list= ClauseVariableList(clause_variable_list,clause_conditions_list);

}
Engine::Engine(){}

void Engine::loop(){
    while(!conclusion_stack.VarStackEmpty()){
        std::string current_con = conclusion_stack.getStackVar();
        updateconclusionStack(current_con);
        std::string property = "";
        int current_cls = conclusion_stack.getStackClause()-2;

        bool fullfilled = true;
        if (current_cls< -1){
            conclusion_stack.popStackVar();
            std::string result = "UNDEFINED";
            var_list.updateCon(current_con, result);
            fullfilled = false;
        }

        int i = 0;
        while(i<var_list.var_size && fullfilled){
            current_cls++;
            std::string clause_var=clause_var_list.getVar(current_cls);
            if(clause_var=="")
                break;
            else{
                if(var_list.searchConVar(clause_var)=="VAR"){
                    property = var_list.getVarProperty(clause_var);
                    if(property != clause_var_list.getCondition(current_cls)){
                        fullfilled = false;
                        conclusion_stack.popStackRule();
                        conclusion_stack.popStackClause();
                        con_list.popRuleNumber(current_con);
                    }
                }
                else{
                    property = var_list.getConProperty(clause_var);
                    if (property==""){
                        conclusion_stack.setStackVar(clause_var);
                        fullfilled = false;
                    }
                    else{
                        if(property != clause_var_list.getCondition(current_cls)){
                            conclusion_stack.popStackRule();
                            conclusion_stack.popStackClause();
                            fullfilled = false;
                            con_list.popRuleNumber(current_con);
                        }
                    }
                }
            }
            i++;
        }

        if(fullfilled){
            con_list.popRuleNumber(current_con);
            int rule_nmb = conclusion_stack.getStackRule();

            conclusion_stack.popStackClause();
            conclusion_stack.popStackRule();
            conclusion_stack.popStackVar();
            std::string result = knowlg_base.getResult(rule_nmb);
            var_list.updateCon(current_con, result);
        }
    }
}
/***/
void Engine::updateconclusionStack(std::string con_var){
    int rule_num = con_list.getRuleNumber(con_var);
    int clause_number = var_list.var_size * ( rule_num / 10 - 1) + 1;

    conclusion_stack.setStackClause(clause_number);
    conclusion_stack.setStackRule(rule_num);
}

std::string Engine::start(std::string conclusion){
    conclusion_stack = ConclusionStack(conclusion);
    loop();
    return var_list.getConProperty(conclusion);
}

Engine::~Engine() = default;

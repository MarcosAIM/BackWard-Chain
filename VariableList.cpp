#include "VariableList.h"

VariableList::VariableList(std::map<std::string, std::string> variable_list,
        std::map<std::string, std::string> conclusion_list)
{
    //ctor
    this->variable_list = variable_list;
    this->conclusion_list = conclusion_list;
    this->var_size = variable_list.size();
}

VariableList::VariableList(){}

std::string VariableList:: getConProperty(std::string con){
    if(conclusion_list.count(con)==1){
        return conclusion_list[con];
    }
    else
        return std::string("not_here_CON");
}

std::string VariableList:: getVarProperty(std::string var){
    if(variable_list.count(var)==1){
        std::string result = variable_list[var];
        if (result ==""){
            std::cout<<"PLEASE ENTER: "<< var<<"\n";
            std::cin>>result;
            variable_list[var] = result;
            return result;
        }
        else
            return result;
    }
    else
        return std::string("not_here_VAR");
}

std::string VariableList::searchConVar(std::string var){
    if(variable_list.count(var)==1){
        return std::string("VAR");
    }
    else
        return std::string("CON");
}

void VariableList::updateCon(std::string con, std::string property){
    std::map<std::string,std::string>::iterator it = conclusion_list.find(con);

    if(it!=conclusion_list.end())
        it->second = property;
}

VariableList::~VariableList()= default;

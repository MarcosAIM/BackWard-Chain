#ifndef ENGINE_H
#define ENGINE_H
#include "VariableList.h"
#include "ConclusionList.h"
#include "ClauseVariableList.h"
#include "ConclusionStack.h"
#include "KnowledgeBase.h"
#include <string>

class Engine
{
    public:
        Engine(std::map<std::string, std::string> variable_list,
               std::map<std::string, std::string> conclusion_list,
               std::map<int, std::string> knowledge_base,
               std::map<std::string, std::queue<int> > con_ls,
               std::vector<std::string> clause_variable_list,
               std::vector<std::string> clause_conditions_list
              );
        /** Default constructor */
        Engine();
        /** Default destructor */
        virtual ~Engine();
        /** function for running loop function given conclusion*/
        std::string start(std::string conclusion);

    private:
        void loop();
        VariableList var_list;
        ConclusionList con_list;
        ClauseVariableList clause_var_list;
        ConclusionStack conclusion_stack;
        KnowledgeBase knowlg_base;

        void updateconclusionStack(std::string con_var);
};

#endif // ENGINE_H

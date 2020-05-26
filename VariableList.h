#ifndef VARIABLELIST_H
#define VARIABLELIST_H
#include <map>
#include <string>
#include <iostream>
class VariableList
{
    public:
        /** Default constructor */
        VariableList();
        VariableList(std::map<std::string, std::string> variable_list,
        std::map<std::string, std::string> conclusion_list);
        /** Default destructor */
        virtual ~VariableList();

        /**Setters*/
        void setVariableList(std::map<std::string, std::string> var_list);
        void setThisVariable(std::string variable, std::string property);

        /**Getters*/
        std::string getConProperty(std::string con);
        std::string getVarProperty(std::string var);
        std::string searchConVar(std::string var);
        void updateCon(std::string con, std::string property);
        int var_size;

    private:
        std::map<std::string, std::string> variable_list;
        std::map<std::string, std::string> conclusion_list;
};

#endif // VARIABLELIST_H

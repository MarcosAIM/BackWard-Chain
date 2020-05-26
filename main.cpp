#include <iostream>
#include <string>
#include "Engine.h"


int main()
{

    //variable_list
    std::map<std::string, std::string> variable_list;
    variable_list.insert( {std::string("MANAGE"), std::string("")} );
    variable_list.insert( {std::string("HELP"), std::string("")} );
    variable_list.insert( {std::string("TEACH"), std::string("")} );
    variable_list.insert( {std::string("MIND"), std::string("")} );
    variable_list.insert( {std::string("HEALTH"), std::string("")} );
    variable_list.insert( {std::string("GEO"), std::string("")} );
    variable_list.insert( {std::string("AGRI"), std::string("")} );
    variable_list.insert( {std::string("BUILD"), std::string("")} );
    variable_list.insert( {std::string("SCI"), std::string("")} );
    variable_list.insert( {std::string("ENG"), std::string("")} );
    variable_list.insert( {std::string("ART"), std::string("")} );
    variable_list.insert( {std::string("NATURE"), std::string("")} );
    variable_list.insert( {std::string("CREATE"), std::string("")} );
    variable_list.insert( {std::string("MATH"), std::string("")} );

	//conclusion_list
	std::map<std::string, std::string> conclusion_list;
	conclusion_list.insert( {std::string("MAJOR"), std::string("")} );
	conclusion_list.insert( {std::string("NATURIST"), std::string("")} );
	conclusion_list.insert( {std::string("HELPER"), std::string("")} );
	conclusion_list.insert( {std::string("STEM"), std::string("")} );
	conclusion_list.insert( {std::string("CREATOR"), std::string("")} );

	//knowledge_base
	std::map<int, std::string> knowledge_base;
	knowledge_base.insert({10, std::string("BUSINESS")});
	knowledge_base.insert({20, std::string("YES")});
	knowledge_base.insert({30, std::string("EDUCATION")});
	knowledge_base.insert({40, std::string("PSYCHOLOGY")});
	knowledge_base.insert({50, std::string("HEALTHCARE")});
	knowledge_base.insert({60, std::string("YES")});
	knowledge_base.insert({70, std::string("AGRICULTURE")});
	knowledge_base.insert({80, std::string("GEOGRAPHY")});
	knowledge_base.insert({90, std::string("YES")});
	knowledge_base.insert({100, std::string("ENGINEERING")});
	knowledge_base.insert({110, std::string("SCIENCE")});
	knowledge_base.insert({120, std::string("YES")});
	knowledge_base.insert({130, std::string("ENGLISH")});
	knowledge_base.insert({140, std::string("ART")});

	//con_ls
	std::queue<int> major_queue;
	major_queue.push(10);
	major_queue.push(30);
	major_queue.push(40);
	major_queue.push(50);
	major_queue.push(70);
	major_queue.push(80);
	major_queue.push(100);
	major_queue.push(110);
	major_queue.push(130);
	major_queue.push(140);

	std::queue<int> naturist_queue;
	naturist_queue.push(60);

	std::queue<int> helper_queue;
	helper_queue.push(20);

	std::queue<int> stem_queue;
	stem_queue.push(90);

	std::queue<int> creator_queue;
	creator_queue.push(120);

	std::map<std::string, std::queue<int> > con_ls;
	con_ls.insert({std::string("MAJOR"),major_queue});
	con_ls.insert({std::string("NATURIST"),naturist_queue});
	con_ls.insert({std::string("HELPER"),helper_queue});
	con_ls.insert({std::string("STEM"),stem_queue});
	con_ls.insert({std::string("CREATOR"),creator_queue});


	//clause_variable_list
	std::vector<std::string> clause_variable_list;
	for(int i = 0; i <196; i++){
    	clause_variable_list.push_back(std::string(""));
	}
	clause_variable_list[0] = "MANAGE";
	clause_variable_list[14] = "MANAGE";
	clause_variable_list[15] = "HELP";
	clause_variable_list[28] = "HELPER";
	clause_variable_list[29] = "TEACH";
	clause_variable_list[42] = "HELPER";
	clause_variable_list[43] = "MIND";
	clause_variable_list[56] = "HELPER";
	clause_variable_list[57] = "HEALTH";
	clause_variable_list[70] = "MANAGE";
	clause_variable_list[71] = "NATURE";
	clause_variable_list[84] = "NATURIST";
	clause_variable_list[85] = "AGRI";
	clause_variable_list[98] = "NATURIST";
	clause_variable_list[99] = "GEO";
	clause_variable_list[112] = "MANAGE";
	clause_variable_list[113] = "MATH";
	clause_variable_list[126] = "STEM";
	clause_variable_list[127] = "BUILD";
	clause_variable_list[140] = "STEM";
	clause_variable_list[141] = "SCI";
	clause_variable_list[154] = "MANAGE";
	clause_variable_list[155] = "CREATE";
	clause_variable_list[168] = "CREATOR";
	clause_variable_list[169] = "ENG";
	clause_variable_list[182] = "CREATOR";
	clause_variable_list[183] = "ART";

	//clause_conditions_list
	std::vector<std::string> clause_conditions_list;
	clause_conditions_list.reserve(196);
    for(int i = 0; i <196; i++){
	    clause_conditions_list.emplace_back("");
	}
	clause_conditions_list[0] = "YES";
	clause_conditions_list[14] = "NO";
	clause_conditions_list[15] = "YES";
	clause_conditions_list[28] = "YES";
	clause_conditions_list[29] = "YES";
	clause_conditions_list[42] = "YES";
	clause_conditions_list[43] = "YES";
	clause_conditions_list[56] = "YES";
	clause_conditions_list[57] = "YES";
	clause_conditions_list[70] = "NO";
	clause_conditions_list[71] = "YES";
	clause_conditions_list[84] = "YES";
	clause_conditions_list[85] = "YES";
	clause_conditions_list[98] = "YES";
	clause_conditions_list[99] = "YES";
	clause_conditions_list[112] = "NO";
	clause_conditions_list[113] = "YES";
	clause_conditions_list[126] = "YES";
	clause_conditions_list[127] = "YES";
	clause_conditions_list[140] = "YES";
	clause_conditions_list[141] = "YES";
	clause_conditions_list[154] = "NO";
	clause_conditions_list[155] = "YES";
	clause_conditions_list[168] = "YES";
	clause_conditions_list[169] = "YES";
	clause_conditions_list[182] = "YES";
	clause_conditions_list[183] = "YES";

    Engine egn = Engine(variable_list,conclusion_list,knowledge_base,con_ls,
                        clause_variable_list,clause_conditions_list);

    const std::string CONCLUSION_VAR = "MAJOR";
    const std::string RESULT = egn.start(CONCLUSION_VAR);
    std::cout << "Career Decider!\n";
    std::cout << CONCLUSION_VAR << ": " << RESULT << "\n";

    return 0;
}

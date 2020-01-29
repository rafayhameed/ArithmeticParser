#include "pch.h"
#include <iostream>
#include "OneStepParser.h"
#include "TwoStepParser.h"

int main()
{
	int testCasesSize = 9;
	OneStepParser oneStepPrsr;
	TwoStepParser twoStepPrsr;
	std::string testCases[] = { "(4 + 5 * (7 - 3)) - 2","4+5+7/2", "10 + 1","85 + 2 * 6" , "100 * 2 + 12" , "100 * ( 2 + 12 )" ,"100 * ( 2 + 12 ) / 14" , "-3","2.4 * 5" };
	std::string testCasesExpectedRslt[] = { "22", "12","invalid", "invalid", "invalid", "invalid", "invalid","invalid", "invalid" };
	try
	{			
		for (int i = 0; i < testCasesSize - 1; i++) {
			std::cout<<testCases[i] + "		||   " + "Expected[" + testCasesExpectedRslt[i] + "]     TwoSteParser[" << twoStepPrsr.calculate(testCases[i]) << "] || OneStepParser[" << oneStepPrsr.calculate(testCases[i]) << "]\n";
		}		
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 0;
	}

	
	int a;
	std::cin>>a;
	return 0;


}
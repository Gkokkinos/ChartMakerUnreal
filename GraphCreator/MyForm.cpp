#include "MyForm.h"



using namespace System;
using namespace System::Windows::Forms;



[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	
	
	GraphCreator::MyForm form;
	
	Application::Run(%form);

}

void GraphCreator::MyForm::getFoo(int &foo) {
	foo = 5;
}

bool GraphCreator::MyForm::drawPoints(std::vector<std::string> pointArray, bool clicked, System::String^ series)
{
	if (!clicked)
	{
		for (int j = 0; j < pointArray.size(); j++)
		{

			if (!pointArray[j].empty())
			{
				float temp = std::stof(pointArray[j]);
				if (temp < 100)
					this->chart2->Series[series]->Points->AddY(temp);
			}
		}
		clicked = true;
	}
	else
	{
		this->chart2->Series[series]->Points->Clear();
		clicked = false;
	}
	return clicked;
}

void GraphCreator::MyForm::createArrays(std::vector<std::string>& time, std::vector<std::string>& frame, std::vector<std::string>& gt, std::vector<std::string>& rt, std::vector<std::string>& gpu, std::vector<std::string>& content, std::string csvName)
{
	std::ifstream file(csvName);
	std::string value;

	int num = 0;
	while (file.good())
	{
		getline(file, value); // read a string 
		std::stringstream eachLine(value);
		while (eachLine.good()) {  //read and seperate values by comma
			std::string temp, temp2, temp3, temp4, temp5, temp6;
			getline(eachLine, temp, ',');
			getline(eachLine, temp2, ',');
			getline(eachLine, temp3, ',');
			getline(eachLine, temp4, ',');
			getline(eachLine, temp5, ',');
			getline(eachLine, temp6, ',');
			//time.push_back(temp);
			frame.push_back(temp2);
			gt.push_back(temp3);
			rt.push_back(temp4);
			//gpu.push_back(temp5);
			//content.push_back(temp6);
		}
		num = 0;
	}
	for (int j = 0; j < 5; j++) //erase unwanted values(?) ---to review---//
	{
		//time[j].erase();
		frame[j].erase();
		gt[j].erase();
		rt[j].erase();
		//gpu[j].erase();
		//content[j].erase();
	}
	
}





    

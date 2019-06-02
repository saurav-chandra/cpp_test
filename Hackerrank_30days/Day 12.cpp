#include<bits/stdc++.h>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student : public Person{
	private:
		vector<int> testScores;  
	public:
		/*
		Student(string firstName, string lastName, int identification, vector<int> scores2)
		{
			//Person* p = new Person(firstName, lastName, identification);
			//this -> firstName = firstName;
			//this -> lastName = lastName;
			//this -> id = identification;
			:Person(firstName, lastName, identification);
			this -> testScores = scores2;
		}
		*/
		
		Student(string firstName, string lastName, int identification, vector<int> scores2):
            Person(firstName, lastName, identification),
            testScores(scores2){}

		char calculate()
		{
			//float average = accumulate( testScores.begin(), testScores.end(), 0.0/ testScores.size());
			float average = 0.0;
			for (auto & score : testScores)
			{
            	average += score;
            }
            average /= testScores.size();

			if(average >= 90 && average <= 100)
				return 'O';
			else if(average >= 80 && average < 90)
				return 'E';
			else if(average >= 70 && average < 80)
				return 'A';
			else if(average >= 55 && average < 70)
				return 'P';
			else if(average >= 40 && average < 55)
				return 'D';
			else if(average < 40)
				return 'T';
		return -1;
		}
		
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

typedef struct Person{
	long current_item;
	long pass_to;
	long status;
	long next_item;
}Person;

void print_vector(vector<Person>);

int main(void){
	long n;
	cin>>n;
	vector<Person> v;
	//cout<<"Pass0\n";
	for(long i = 0;i<n;++i){
		long temp_pass_to = 0;
		cin>>temp_pass_to;
		Person temp_person;
		temp_person.current_item = i;
		temp_person.pass_to = temp_pass_to - 1;
		temp_person.status = 0;
		temp_person.next_item = i;
		//cout<<"A";
		v.push_back(temp_person);
		//cout<<"B";
	}
	//cout<<"Pass1\n";
	bool check = 0;
	long count = 0;
	do{
		check = 1;
		//count++;
		//cout<<"Before\n";
		//print_vector(v);
		for(long i = 0;i<n;++i){
			//cout<<"v.at(v.at(i).pass_to).next_item = "<<v.at(v.at(i).pass_to).next_item << ", v.at(i).current_item = "<<v.at(i).current_item<<" \n----------\n";
			//v.at(i).current_item = v.at(i).next_item;
			//cout<<"Pass2.1\n";
			if(v.at(i).status == 1)
				continue;
			//cout<<"Pass2.2\n";
			//cout<<"v.at(v.at(i).pass_to).next_item = "<<v.at(v.at(i).pass_to).next_item << ", v.at(i).current_item = "<<v.at(i).current_item<<" \n";
			v.at(v.at(i).pass_to).next_item = v.at(i).current_item;
			//cout<<"Pass2.3\n";
			if(v.at(i).current_item == i && count > 0){
				v.at(i).status = 1;
			}else{
				check = 0;
			}
		}
		for(long i= 0;i<n;++i){
			v.at(i).current_item = v.at(i).next_item;
		}
		//cout<<"After\n";
		//print_vector(v);
		count++;
	}while(check == 0);
	cout<<count-1<<endl;
	return 0;
}


void print_vector(vector<Person> v){
	for(Person i:v){
		cout<<i.current_item<<", "<<i.next_item<<", "<<i.pass_to<<", "<<i.status<<"   ";	
	}
	cout<<endl;
}


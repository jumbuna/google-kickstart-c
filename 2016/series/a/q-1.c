#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//65-90 = A-Z
//line 1 = number of test case
/*test cases*/
//line 1 = number of people in the country
//line i = person at i'th position in test case
//each name contains atleast 20 characters
//each name contains atleast one alphabet letter
//the country uses the alphabets A-Z

/*output*/
//format: Case #x: y, x=test case number(index starts at 1 and y = name of the leader.

/*limits*/
//1 <= numberOfTestCases <= 100
//Time limit 20 sec @ test set
//memory limit 1 GB

//proposed algorithm
//1.maintain the following variable for each test set
//	- currentLeaderName = name of the current leader at a particular point
//	- testCaseNumber = case number for the current leader
//  - currentLeaderUniqueChars = number of characters(A-Z) in the current leader's name
//2.finding number of unique chars(A-Z) in a name
// 	-sort(quick sort) the chars in the name to bring identical letters next to each other
// 	-loop through the sorted name chars
//	-maintain the following variables
//		-previousUniqueChar = previous unique character
//		-noOfUniqueChars = number of unique characters at particular point
//3.incase of a tie sort the names lexicographically and take the first one


void sortCharsInName(char *name, int begin, int end) {
	if(begin < end) {
		int pivot = end;
		for(int i = end-1; i >= 0; i--) {
			if(name[i] > name[pivot]) {
				char temp = name[pivot];
				name[pivot] = name[i];
				name[i] = name[--pivot];
				name[pivot] = temp;
			}
		}
		sortCharsInName(name, begin, pivot-1);
		sortCharsInName(name, pivot+1, end);
	}
}

int uniqueCharsInName(char *name) {
	char tempPersonName[21];
	strcpy(tempPersonName, name);
	int len = strlen(name);
	sortCharsInName(tempPersonName, 0, len-1);
	char previousUniqueChar = tempPersonName[0];
	int uniqueCharacters = 1;
	for(int i = 1; i < len; i++) {
		if(tempPersonName[i] != previousUniqueChar && tempPersonName[i] != ' ') {
			previousUniqueChar = tempPersonName[i];
			++uniqueCharacters;
		}
	}
	return uniqueCharacters;
}

void findLeaderFromTestSet(int numberOfcasesInSet, int caseNumber) {
	int currentLeaderUniqueChars = 0;
	size_t maxCharsPerName = 21;
	char currentLeaderName[maxCharsPerName];
	char *personName = (char *) malloc(maxCharsPerName);
	int personsUniqueChars;
	//printf("%i\n", numberOfcasesInSet);
	for(int i = 1; i <= numberOfcasesInSet; i++) {
		getline(&personName, &maxCharsPerName, stdin);
		personsUniqueChars = uniqueCharsInName(personName);
		if(personsUniqueChars > currentLeaderUniqueChars) {
			currentLeaderUniqueChars = personsUniqueChars;
			strcpy(currentLeaderName, personName);
		} else if(personsUniqueChars == currentLeaderUniqueChars) {
			if(strcmp(personName, currentLeaderName) < 0) {
				currentLeaderUniqueChars = personsUniqueChars;
				strcpy(currentLeaderName, personName);
			}
		}
	}
	
	free(personName);
	
	printf("Case #%i: %s", caseNumber, currentLeaderName);
}
		
int main(int argc, char *argv[]) {
	int numberOfTestSets;
	int numberOfCasesInTestSet;
	scanf("%i", &numberOfTestSets);
	for(int i = 0; i < numberOfTestSets; i++) {
		scanf("%i", &numberOfCasesInTestSet);
		getchar();
		findLeaderFromTestSet(numberOfCasesInTestSet, i+1);
	}
}

/*

2
3
ADAM
BOB
JOHNSON
2
A AB C
DEF

*/
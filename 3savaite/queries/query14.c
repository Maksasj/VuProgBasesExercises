#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade
	
	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades	
	
	char languages[100];		// spoken languages
} Student;

int stringLength(char string[], int size) {
	int a = 0;
	for(int x = 0; x < size; x++) {
		if(string[x] != '\0') {
			a++;
		} else {
			break;
		}
	}
	return a;
}

int ifStringEqual(char given[], char filter[]) {	
	for(int i = 0; i < stringLength(filter, 30); i++) {
		if(given[i] != filter[i]) {
			return 0;
		}
	}

	return 1;
}

int ifArrayHaveSuch(char courses[10][30], int load, char course[]) {
	for(int i = 0; i < load; i++) {
		if(ifStringEqual(courses[i], course)) {
			return 1;
		}
	}
	return 0;
}

int vienintStudentasCourse(Student students[], int count, Student student) {
	int anw = 0;
	for(int j = 0; j < student.load; j++) {
		int tmp = 0;
		for(int i = 0; i < count; i++) {
			if(ifArrayHaveSuch(students[i].courses, students[i].load, student.courses[j])) {
				tmp = 1;
			}
		}
		anw += tmp;
	}
	
	return (anw >= student.load ? 1 : 0 );
}

int main(int argc, char *argv[]) {
	FILE *db = NULL;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");
		
	if (db){							
		Student students[1000];			// all the data goes here
		int size = 0;					// how many students in database
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded succesfully\n", size);
		
		// MODIFY CODE BELOW
		
		int counterDemo = 0; // for counting students
		
		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			
			if(vienintStudentasCourse(students, size, students[i])){ // *** first filter, conditions on the student
				printf("\nStudent name: %s, surname: %s \nCourse: %d \nAverage mark: %f\nNumber of courses: %d \n", s.name, s.surname, s.course, s.average, s.load); // print student data
				int anotherDemo = 0; // for counting courses/grades
				printf("Courses: \n");
				for (int i = 0; i < s.load; ++i){ // process each course taken by the student
					if(1){ // *** second filter, conditions on the course/grade
						++anotherDemo; // counting courses
						printf("    %s %d \n", s.courses[i], s.grades[i]);
					}
				}
				printf("Languages:\n    %s \n", s.languages);
						
				if (anotherDemo == s.load) // *** third filter, various other conditions			
					++counterDemo; // counting studfents
			}
		}
		printf("\nFilter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	
	return 0;
}
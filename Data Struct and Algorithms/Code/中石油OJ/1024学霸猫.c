#include <stdio.h>
#include <string.h>

int main() {
	char courseName[60], tName[60], startTime[60], endTime[60];
	int startHour, endHour, startMin, endMin;
	int tHour, tMin;
	int resultHour = 0, resultMin = 0; char resultCourseName[60] = "";
	
	int i, j, count = 0;
	
	while(scanf("%s %s %s", courseName, startTime, endTime) != EOF) {
		startHour = 0, endHour = 0, startMin = 0, endMin = 0;
		for(i = 0; i < strlen(startTime); i++) {
			if(startTime[i] == ':') {
				for(j = 0; j < i; j++) {
					startHour *= 10;
					startHour += startTime[j] - '0';
				}
				for(j = i + 1; j < strlen(startTime); j++) {
					startMin *= 10;
					startMin += startTime[j] - '0';
				}
				break;
			}
		}
		
		for(i = 0; i < strlen(endTime); i++) {
			if(endTime[i] == ':') {
				for(j = 0; j < i; j++) {
					endHour *= 10;
					endHour += endTime[j] - '0';
				}
				for(j = i + 1; j < strlen(endTime); j++) {
					endMin *= 10;
					endMin += endTime[j] - '0';
				}
				break;
			}
		}
		
		tHour = endHour - startHour;
		tMin = endMin - startMin;
		if(tMin < 0) {
			tHour--;
			tMin += 60;
		}
		
		if(tHour > resultHour || tHour == resultHour && tMin > resultMin) {
			resultHour = tHour;
			resultMin = tMin;
			strcpy(resultCourseName, courseName);
		}	
		count++;
	}
	printf("%s %d:%d", resultCourseName, resultHour, resultMin);
	
} 

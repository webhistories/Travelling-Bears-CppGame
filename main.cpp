#include <iostream>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <string.h>
#include <algorithm>
#include <ctime>
#define ESCAPE 27

using namespace std;

int i, x=225 /* x is used in logo function */;
	int logonum[8] ={245,0,244,58,368,59,369,-1};
	int levelnum[8] ={0,75,75,74,75,1,1,-1};
	int box[8] = {198,105,463,105,462,438,197,438};
int roundbox[40] = {207,131,209,122,214,116,220,114,436,115,444,120,448,125,450,135,450,155,451,410,448,417,441,422,435,424,219,424,213,422,208,415,208,401,208,259,206,138,207,131};
int level; //level counter
	//graphics
	
int logoNumber = 0;
char lnArr[100];
int hintNum=5;
	
char validLetters[100]={"abcdefghijklmnopqrstuvwxyz"};
int miss = 3;
char missArr[100], hintNumArr[100];
void startPage();
void gameOver();

int playLogic (char word[100]){
char asterisk[100] = {"****************************************"}, dispArr[100], display[100], posArr[100], correctArr[100];

strcpy(display, word);
	int correct = 0, incorrect = 0;
		char response, respArr[100];
		char responseB;

memcpy(display, asterisk, strlen(display));

setcolor(BLACK);
setbkcolor(WHITE);
settextstyle(3,0,4);
sprintf(dispArr, "%s", display);
outtextxy(263,331,dispArr);
//x = x+25;

while(1)
{
	

setfillstyle(SOLID_FILL, RED);
bar(562,0,639,76);
rectangle(562,0,639,76);

//life
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(580,9, "LIFE");
settextstyle(2,0,9);
sprintf(missArr,"%d",miss);
outtextxy(590,35, missArr); 

//hintnum
setfillstyle(SOLID_FILL, RED);
setcolor(BLACK);
bar(373,470,244,450);
rectangle(373,470,244,450);

settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(256,450, "HINT / S: ");
sprintf(hintNumArr,"%d",hintNum);
outtextxy(333,450, hintNumArr);

//after backspace 
deleteAfter:
hintEnd:
setcolor(BLACK);
setbkcolor(WHITE);
settextstyle(10,0,1);
outtextxy(220, 360, "Enter letter:");
response = tolower(getch());
setcolor(BLACK);
setbkcolor(WHITE);
sprintf(respArr,"%c",response);
outtextxy(370,360, respArr);




//else not backspace
//else {


char *valid;
valid = strstr(validLetters, respArr);


if(valid>0){
	settextstyle(2,0,6);
	setcolor(RED);
	setbkcolor(WHITE);	
	outtextxy(220, 380, "Press any key to check!");
	outtextxy(213, 400, "Press BACKSPACE to delete");
	responseB = getch();
	setfillstyle(SOLID_FILL, WHITE);
	bar(214,379,442,423);
	bar(364,361,395,380);
	setcolor(BLACK);
	
if(responseB==127 || responseB==8){
			setfillstyle(SOLID_FILL, WHITE);
			bar(362,360,392,380);
			goto deleteAfter;
				}//if backspace

}

	balik:

char *position, *repeat;
position = strstr(word, respArr);
int found = 0;

if(position>0){
	
	repeat = strstr(display, respArr);
	
	if(repeat>0){
	settextstyle(2,0,7);
	setcolor(RED);
	setbkcolor(WHITE);	
	outtextxy(220, 380, "Letter already entered!");
	settextstyle(2,0,6);
	outtextxy(220, 400, "Press any key to continue..");
	getch();
	setfillstyle(SOLID_FILL, WHITE);
	bar(219,382,438,419);
	}
	
	else{

	int numpos = position-word;
	memcpy(&display[numpos], respArr, 1);
	found++;
	settextstyle(10,0,2);
	sprintf(posArr,"%s",display);
	outtextxy(263, 331,posArr);
	correct++;

	if(found>0)
	for(i=0; i<=found; i++)
	{
	position = strstr(&word[numpos+1], respArr);
	if(position>0){
		correct++; 
		numpos = position-word;
		memcpy(&display[numpos], respArr, 1);
	settextstyle(10,0,2);
	sprintf(posArr,"%s",display);
	outtextxy(263, 331,posArr);
	} //if(position>0)
	
	else{
		position++;} //else found
	 } //else 
}//for

	 
	}// if(position>0)
if(position<=0) {
	
if(valid>0){

settextstyle(2,0,7);
	setcolor(RED);
	setbkcolor(WHITE);	
	outtextxy(220, 380, "Incorrect input!");	
	outtextxy(220, 400, "Press any key to continue..");
	getch();
	setfillstyle(SOLID_FILL, WHITE);
	bar(212,378,442,421);
	
	miss--;
}//if valid


else {

	if (GetAsyncKeyState(VK_TAB))//hint
	{
	
	if(hintNum<=5 && hintNum>0){
		hintNum--;
	srand(time(0));
	char hint;
	invalid:
	hint = word [rand() % strlen(word)];
	response = hint;
	sprintf(respArr,"%c",response);
	repeat = strstr(display, respArr);
	if(repeat>0)
	goto invalid;
	else{
	
	goto balik;}
	}
	if(hintNum<=0)
	setcolor(RED);
	setbkcolor(WHITE);	
	settextstyle(2,0,7);	
	outtextxy(220, 380, "You ran out of hints! ");
	outtextxy(220, 400, "Press any key to try again..");
	getch();
	setfillstyle(SOLID_FILL, WHITE);
	bar(212,378,442,421);
	goto hintEnd;
	}//if tab
		

		if (GetAsyncKeyState(VK_ESCAPE)) //back
				{
		closegraph();
		startPage();
		 }//if 
		
			
		else{
	setcolor(RED);
	setbkcolor(WHITE);	
	settextstyle(2,0,7);	
outtextxy(220, 380, "Enter letters only!");
	outtextxy(220, 400, "Press any key to try again..");
	getch();
	setfillstyle(SOLID_FILL, WHITE);
	bar(212,378,442,421); }//else in

}

}//if(position<=0)
if(miss==0){

for(i=0; i<3; i++)
{
setfillstyle(SOLID_FILL, RED);	
bar(568,40,635,69);
delay(100);
setcolor(WHITE);
setbkcolor(RED);	
settextstyle(2,0,9);
sprintf(missArr,"%d",miss);
outtextxy(590,35, missArr); 
delay(100);
setfillstyle(SOLID_FILL, RED);	
bar(568,40,635,69);
delay(100);
sprintf(missArr,"%d",miss);
outtextxy(590,35, missArr); 

}
settextstyle(2,0,7);
		setcolor(RED);
	setbkcolor(WHITE);	
outtextxy(220, 380, "GAME OVER!");
miss=3;
level=0;
logoNumber=0;
level=0;
hintNum=5;
delay(1000);
gameOver();
 } //if miss
if(correct==strlen(word)){
	setcolor(RED);
	setbkcolor(WHITE);	
	settextstyle(2,0,7);	
outtextxy(220, 380, "Good Job!");
	outtextxy(220, 400, "Press any key to continue..");
	getch();
	setfillstyle(SOLID_FILL, WHITE);
	bar(213,120,443,421);
	bar(218,120,440,382);
	bar(211,138,447,414);

break; }//if correct
//}//else



}//while
}//playLogic

/*******************************************************************MAP***********************************************************/

void map(){

//map
int mapbox [] = {60,60, 60,459, 619,459, 619,60, 60,60};

//int 0 [] = {60,0, 60,52, 626,52, 626,467, 53,467, 53,60, 36,60, 36,478,
//				 638,478, 638,0, 60,0};

//int box [] = {0,0, 52,0, 52,52, 0,52, 0,0};

//int sideborder [] = {0,60, 28,60, 28,478, 0,478, 0,60};

//level 1 

int lvl1ptree1 [] = {569,390, 565,377, 563,393, 569,390};

int lvl1ptree2 [] = {559,396, 550,379, 543,402, 550,402, 559,396};

int lvl1ptree3 [] = {538,402, 544,383, 546,390, 543,402, 538,402};

int lvl1ptree4 [] = {461,420, 465,379, 480,412, 476,417, 472,417, 468,417,
					 465,419, 461,420};
					 
int lvl1ptree5 [] = {472,417, 475,382, 480,412, 476,417, 472,417};

int lvl1ptree6 [] = {449,427, 459,388, 461,420, 457,423, 453,425, 449,427};

int grncave [] = {569,446, 570,391, 551,403, 534,404, 557,412, 561,414,
				  560,419, 556,427, 554,429, 553,430, 551,429, 547,425,
				  544,424, 542,425, 540,428, 534,434, 533,436, 533,439,
				  535,443, 539,446, 569,446};

int mncave [] = {534,404, 557,412, 561,414, 560,419, 556,427, 554,429,
				 553,430, 551,429, 547,425, 544,424, 542,425, 540,428,
				 534,434, 533,436, 533,439, 531,442, 475,441, 483,431,
				 483,427, 482,423, 480,420, 498,404, 501,402, 508,403,
				 511,403, 515,401, 519,402, 528,405, 534,404};
				 
int grncave2 [] = {531,405, 528,405, 519,402, 515,401, 511,403, 508,403,
				   501,402, 498,404, 480,420, 476,417, 498,399, 500,398,
				   503,397, 507,397, 512,397, 517,398, 521,400, 526,402,
				   530,404, 531,405};
				   
int lrock [] = {476,417, 480,420, 482,423, 483,423, 483,427, 483,431,
				475,441, 441,442, 443,438, 446,435, 449,431, 452,428,
				456,426, 459,424, 463,422, 466,420, 469,418, 472,417,
				475,417, 476,417};
				
int grass1 [] = {475,441, 478,438, 479,436, 481,434, 483,432, 485,433,
				486,434, 487,434, 488,433, 490,432, 491,432, 493,432,
				494,434, 496,434, 498,434, 498,440, 498,441, 475,441};
				
int lvl1door [] = {498,441, 498,440, 498,434, 498,427, 498,426, 499,424,
				   500,423, 501,422, 502,421, 504,421, 505,422, 506,423,
				   507,424, 508,426, 508,428, 508,434, 508,441, 498,441};
				   
int rrock [] = {508,441, 508,434, 510,433, 513,433, 515,433, 517,434, 
				519,435, 521,436, 523,437, 526,438, 528,440, 530,441,
				508,441};
				
int grass2 [] = {441,442, 443,438, 446,435, 446,432, 445,430, 443,429,
				 441,427, 440,426, 439,427, 437,428, 435,429, 433,430,
				 432,431, 431,433, 430,434, 428,434, 425,434, 423,434,
				 422,435, 421,437, 421,441, 423,444, 425,445, 427,445,
				 429,445, 431,444, 432,442, 434,443, 439,442, 441,442};
				 
int lvl1trunk [] = {443,429, 441,427, 440,426, 439,427, 437,428, 435,429,
					433,430, 432,428, 433,425, 433,421, 433,418, 434,413,
					433,409, 434,405, 433,403, 428,399, 432,401, 433,401,
					434,400, 433,398, 434,396, 434,394, 433,392, 433,390,
					434,387, 433,385, 435,386, 437,388, 440,388, 440,394,
					440,397, 441,402, 439,404, 438,406, 438,412, 439,414,
					441,416, 442,418, 442,420, 443,423, 444,426, 445,428,
					443,429};
					
int lvl1leaves [] = {433,385, 435,386, 437,388, 440,388, 443,389, 445,389,
					 447,388, 449,389, 451,388, 453,388, 454,386, 456,385,
					 463,376, 463,369, 454,360, 449,360, 447,359, 447,357,
					 445,356, 443,355, 440,354, 425,354, 423,354, 422,356,
					 422,358, 422,359, 420,357, 418,358, 418,361, 419,364,
					 417,365, 415,366, 415,368, 417,370, 422,375, 423,376,
					 424,378, 423,380, 423,382, 425,383, 427,386, 429,387,
					 431,386, 433,385};
					 
//level 2

int benchl [] = {137,441, 140,438, 185,438, 188,441, 137,441};

int bencht [] = {185,436, 185,425, 173,425, 171,424, 169,423, 167,422, 
				 159,422, 157,423, 155,424, 153,425, 140,425, 140,436,
				 185,436};
				 
int dpconr [] = {185,436, 185,438};

int dpconl [] = {140,436, 140,438};

int dpstandr [] = {185,441, 185,448};

int dpstandl [] = {140,441, 140,448};

int lvl2trunk [] = {116,454, 110,452, 112,429, 107,425, 108,423, 112,426,
					112,420, 106,413, 108,411, 114,417, 118,411, 121,413,
					122,422, 121,419, 115,426, 116,454};
					
int lvl2trunkb [] = {176,421, 180,422, 180,400, 185,397, 184,395, 181,397,
					 184,391, 183,388, 179,393, 174,388, 172,390, 178,397,
					 178,400, 174,397, 173,400, 177,403, 176,421};
					 
int lvl2leavesb [] = {180,411, 180,400, 185,397, 184,395, 181,397, 184,391,
					  183,388, 179,393, 174,388, 172,390, 178,397, 178,400, 
					  177,403, 177,411, 174,410, 170,408, 167,406, 165,404, 
					  163,402, 162,400, 161,397, 160,394, 159,391, 159,378,
					  161,373, 163,369, 166,366, 168,363, 171,361, 175,360,
					  183,360, 187,361, 191,363, 194,366, 196,368, 198,372,
					  200,377, 200,391, 199,394, 198,397, 197,400, 195,403, 
					  192,406, 190,408, 187,410, 183,411, 180,411};
							
int lampstand [] = {199,446, 199,448, 191,448, 191,446, 193,446, 193,441,
					194,440, 194,413, 195,413, 195,440, 196,441, 196,446,
					199,446};
					
int lamplight [] = {195,413, 199,405, 198,404, 191,404, 190,405, 194,413,
					195,413};
					
int lamptop [] = {198,404, 191,404, 191,404, 193,402, 196,402, 198,404};

int lvl2leaves [] = {116,440, 115,426, 122,422, 121,419, 116,422, 121,413,
					 118,411, 114,417, 108,411, 106,413, 112,420, 112,426,
					 108,423, 107,425, 112,429, 110,432, 111,439, 108,439,
					 106,438, 104,436, 102,435, 100,434, 98,432, 96,430,
					 94,428, 93,425, 92,423, 91,420, 90,417, 89,414,
					 89,403, 89,400, 90,397, 91,394, 92,390, 94,387,
					 95,384, 98,381, 101,378, 104,376, 107,375, 110,374,
					 119,374, 122,375, 124,376, 126,377, 129,379, 131,381,
					 135,385, 138,388, 138,391, 140,394, 141,398, 141,402,
					 141,413, 140,416, 139,419, 138,422, 137,425, 135,428,
					 133,430, 131,432, 129,434, 127,436, 124,438, 121,439,
					 119,440, 116,440};	
					 
//level 3
//school
int gwall [] = {79,273, 79,267, 165,267, 165,273, 79,273};

int pwall [] = {79,267, 165,267, 165,245, 142,245, 122,229, 102,245,
				79,245, 79,267};
				
int roof1 [] = {79,245, 102,245, 99,242, 114,229, 81,229, 77,245};

int roof2 [] = {165,245, 142,245, 145,242, 130,229, 163,229, 167,245,
				165,245};
				
int topperr [] = {163,229, 163,226, 130,226, 130,229, 163,229};

int topperl [] = {114,229, 81,229, 81,226, 114,226, 114,229};

int brownroof [] = {142,245, 145,242, 130,229, 122,224, 114,229, 99,242,
					102,245, 122,229, 142,245};
					
int attic [] = {130,229, 130,226, 130,216, 114,216, 114,226, 114,229, 
				122,224, 130,229};
				
int aroof [] = {132,215, 122,208, 112,215, 132,215};

int flag [] = {122,202, 127,202, 127,203, 132,203, 130,205, 132,207,
			   126,207, 126,205, 122,205, 122,202};
			   
int flagstand [] = {122,208, 122,202};

int doorway [] ={130,266, 129,266, 129,252, 115,252, 115,266, 114,266,
				 114,251, 130,251, 130,266};
				 
int lvl3door [] = {128,266, 128,253, 116,253, 116,266, 128,266};

int lvl3winar [] = {138,247, 144,247, 144,264, 138,264, 138,247};

int lvl3winbr [] = {147,247, 153,247, 153,264, 147,264, 147,247};

int lvl3wincr [] = {157,247, 163,247, 163,264, 157,264, 157,247};

int lvl3winal [] = {107,247, 107,264, 101,264, 101,247, 107,247};

int lvl3winbl [] = {97,247, 97,264, 91,264, 91,247, 97,247};

int lvl3wincl [] = {88,247, 88,264, 82,264, 82,247, 88,247};

int step1 [] = {136,267, 108,267};

int step2 [] = {138,269, 106,269};

int step3 [] = {141,271, 103,271};

int lvl3path [] = {102,275, 96,297, 149,297, 142,275, 102,275};

int lvl3grassa [] = {78,267, 72,267, 72,297, 96,297, 102,274, 78,274,
					 78,267};

int lvl3trunk [] = {193,288, 191,288, 196,271, 200,268, 199,267, 197,268,
					198,266, 200,263, 199,262, 196,265, 192,262, 191,263,
					194,271, 191,269, 190,270, 194,273, 193,288};
					
int lvl3leaves [] = {197,280, 196,271, 200,268, 199,267, 197,268, 198,266,
					 200,263, 199,262, 196,265, 192,262, 191,263, 194,271,
					 191,269, 190,270, 194,273, 194,279, 192,279, 190,278,
					 188,277, 186,276, 184,274, 182,272, 181,270, 181,268,
					 180,266, 180,264, 180,255, 180,253, 181,251, 181,249,
					 183,247, 184,245, 186,243, 188,241, 190,239, 192,238, 
					 199,238, 201,239, 202,240, 204,241, 206,243, 208,245,
					 209,247, 210,249, 211,250, 211,252, 212,254, 212,256, 
					 213,258, 213,263, 212,265, 212,267, 211,269, 210,271,
					 209,273, 207,275, 205,277, 203,278, 201,279, 199,280,
					 197,280};
					 
int lvl3grassb [] = {149,297, 142,274, 166,274, 166,267, 198,267, 198,289, 
					 198,297, 149,297};

//level  4
int station [] = {307,255, 357,255, 357,257, 313,257, 313,259, 319,259,
				  319,292, 322,292, 322,323, 319,323, 319,328, 307,328,
				  307,259, 311,259, 311,257, 307,257, 307,255};
				  
int detailbox [] = {309,294, 320,294, 320,320, 309,320, 309,294};

int car [] = {336,300, 359,300, 362,306, 366,310, 367,311, 367,314,
			  366,315, 365,317, 365,321, 361,321, 359,320, 336,320,
			  334,321, 330,321, 329,318, 328,316, 327,315, 327,311,
			  328,310, 332,306, 336,300};
			  
int hlr [] = {364,311, 365,312, 362,314, 360,313, 364,311};

int hll [] = {329,312, 330,311, 334,313, 332,314, 329,312};

int ws [] = {334,306, 337,300, 358,300, 361,306, 334,306};

int cardet [] = {339,314, 356,314, 354,318, 341,318, 339,314};

int rt [] = {365,321, 364,323, 362,323, 361,321, 365,321};

int lt [] = {334,321, 333,323, 331,323, 330,321, 334,321};

//level 5
int lvl5table1 [] = {588,310, 595,305, 594,296, 594,294, 592,293, 587,298,
					 580,294, 580,292, 578,294, 571,290, 569,289, 562,287,
					 562,284, 559,283, 553,282, 553,279, 549,282, 549,291,
					 588,310};
					 
int box1 [] = {587,298, 580,294, 587,295, 591,290, 591,293, 587,298};

int cyan1 [] = {591,290, 587,295, 580,292, 585,286, 591,290};

int box2 [] = {580,292, 578,294, 571,290, 571,287, 577,290, 582,284, 
			   582,288, 580,288, 580,292};
			   
int cyan2 [] = {582,284, 577,290, 571,287, 575,280, 582,284};

int box3 [] = {569,289, 562,287, 562,284, 569,286, 573,280, 573,284, 569,289};

int cyan3 [] = {573,280, 569,286, 562,284, 566,276, 573,280};

int box4 [] = {559,283, 553,282, 553,279, 560,282, 564,276, 565,278, 562,284, 559,283};

int cyan4 [] = {564,276, 559,282, 553,279, 557,272};

int tentmn [] = {600,266, 593,279, 593,282, 550,261, 550,256, 562,245, 600,266};

int stand [] = {600,266, 600,301, 599,301, 597,272, 600,266};

int lvl5tablea [] = {537,281, 537,290, 502,316, 502,307, 537,281};

int lvl5tableb [] = {502,307, 502,316, 492,309, 492,300, 502,307};

int lvl5tablec [] = {502,307, 492,300, 529,273, 537,281, 502,307};

int leg1 [] = {593,279, 594,294};

int leg2 [] = {550,260, 555,275};

int leg3 [] = {593,279, 550,256};				 					 								   

//level 6

int lvl6build1 [] = {573,156, 567,156, 567,129, 548,129, 548,120, 573,120, 
					 573,156};
					 
int lvl6win1 [] = {567,156, 567,129, 548,129, 548,156, 567,156};

int lvl6build2 [] = {548,156, 548,98, 522,98, 522,156, 548,156};

int lvl6detb [] = {522,143, 548,143, 548,138, 522,138, 522,143};

int lvl6win2a [] = {525,107, 525,119, 536,119, 536,107, 525,107};

int lvl6win2b [] = {536,119, 545,119, 545,132, 536,132, 536,119};

int lvl6build3 [] = {503,156, 503,120, 522,120, 522,107, 497,107, 497,156, 
					 503,156};
					 
int lvl6win3 [] = {522,156, 522,120, 503,120, 503,156, 522,156};

int bboard [] = {548,93, 548,81, 522,81, 522,93, 548,93};

int bboardr [] = {545,98, 545,93};

int bboardl [] = {525,93, 525,98};

int lvl6road [] = {595,158, 475,158, 457,169, 595,169, 595,158};

int lvl6lighta [] = {589,157, 589,119, 588,119, 588,157, 589,157};

int lvl6aright [] = {590,121, 591,120, 592,119, 593,119, 594,118, 600,118};

int lvl6aleft [] = {587,121, 586,120, 584,119, 583,119, 582,118, 577,118};

int lvl6lightb [] = {481,157, 480,157, 480,119, 481,119, 481,157};

int lvl6bright [] = {482,121, 483,120, 484,119, 485,119, 486,118, 493,118};

int lvl6bleft [] = {479,121, 478,120, 477,119, 476,119, 475,118, 469,118};

//level 7
int ptruck [] = {412,165, 412,122, 411,122, 404,130, 404,152, 366,152, 
				 364,153, 362,154, 359,155, 356,156, 353,158, 350,160,
				 348,162, 347,164, 346,165, 384,165, 385,159, 400,159,
				 402,165, 412,165};
				 
int lvl7win1 [] = {404,130, 404,152, 366,152, 366,130, 404,130};

int lvl7roof [] = {411,122, 404,130, 366,130, 360,122, 359,119, 413,119, 411,122};

int rtruck [] = {366,152, 364,153, 362,154, 359,155, 356,156, 353,158,
				 350,160, 348,162, 347,164, 346,165, 344,159, 330,159,
				 328,165, 323,165, 325,150, 330,145, 340,122, 359,122,
				 360,122, 366,130, 366,152};
				 
int lining [] = {346,165, 384,165, 385,159, 400,159, 402,165, 412,165,
			     412,167, 400,167, 400,164, 399,163, 398,162, 397,161,
			     389,161, 388,162, 387,163, 386,164, 386,167, 343,167, 
			     343,164, 342,163, 341,162, 340,161, 334,161, 333,162,
			     332,163, 331,164, 331,167, 323,167, 323,165, 328,165, 
			     330,159, 344,159, 346,165};
			   
int lvl7tire1 [] = {400,167, 400,164, 399,163, 398,162, 397,161, 389,161,
					388,162, 387,163, 386,164, 386,167, 387,169, 388,170,
					389,171, 390,172, 395,172, 396,171, 397,170, 398,169,
					399,168, 400,167};
					
int lvl7tire2 [] = {343,167, 343,164, 342,163, 341,162, 340,161, 334,161,
					333,162, 332,163, 331,164, 331,167, 332,168, 333,169,
					333,170, 335,171, 339,171, 340,170, 341,169, 342,168,
					343,167};

int lvl7win2 [] = {347,130, 355,130, 355,145, 347,145, 347,130};

int lvl7win3 [] = {337,132, 339,132, 339,146, 331,146, 337,132};

int pcncblngkt [] = {380,178, 403,178, 399,199, 377,199, 380,178};

int pcnctbl [] = {341,180, 343,176, 366,176, 367,180, 341,180};

int pcncleg1 [] = {366,180, 366,193};

int pcncleg2 [] = {341,180, 341,193};

int pcncleg3 [] = {344,180, 344,189};

int pcncleg4 [] = {365,180, 365,189};

//level 8
int watchtower [] = {90,146, 90,100, 84,100, 76,86, 83,86, 83,82, 
					 87,82, 87,75, 90,73, 104,73, 107,75, 107,82,
					 110,82, 110,86, 117,86, 110,100, 105,100, 105,126,
					 103,128, 101,130, 99,132, 97,134, 95,137, 93,139,
					 92,142, 91,144, 90,146};
					 
int wtbar [] = {99,132, 99,103, 95,103, 95,137, 97,134, 99,132};

int lvl8win1 [] = {79,90, 114,90, 112,95, 82,95, 79,90};

int lvl8win2 [] = {88,82, 88,77, 106,77, 106,82, 88,82};

int airport [] = {90,146, 91,144, 92,142, 93,139, 95,137, 97,134, 
				  99,132, 101,130, 103,128, 105,126, 107,124, 109,122,
				  111,120, 113,118, 115,117, 117,115, 119,114, 121,113,
				  123,112, 125,111, 127,110, 129,109, 131,108, 133,107,
				  135,106, 137,105, 139,104, 141,103, 144,102, 147,101,
				  151,100, 176,100, 181,101, 185,102, 187,103, 190,104,
				  192,105, 194,106, 196,107, 198,108, 200,109, 202,110,
				  204,111, 206,112, 208,113, 210,114, 212,115, 214,117, 
				  216,119, 218,121, 220,123, 222,125, 224,127, 226,129,
				  228,131, 230,133, 232,135, 235,140, 236,142, 238,144,
				  239,146, 90,146};
				  
int lvl8wina [] = {93,145, 97,145, 97,139, 95,141, 94,143, 93,145};
int lvl8winb [] = {100,145, 104,145, 104,130, 102,133, 100,135, 100,145};
int lvl8winc [] = {107,145, 112,145, 112,123, 110,125, 108,127, 107,128, 
				   107,145};
int lvl8wind [] = {114,145, 119,145, 119,117, 117,119, 114,121, 114,145};
int lvl8wine [] = {121,145, 126,145, 126,113, 123,114, 121,116, 121,145};
int lvl8winf [] = {129,145, 134,145, 134,109, 131,110, 129,112, 129,145};
int lvl8wing [] = {136,145, 141,145, 141,107, 138,107, 136,108, 136,145};
int lvl8winh [] = {144,145, 148,136, 148,105, 146,105, 144,106, 144,145};
int lvl8wini [] = {151,137, 153,136, 156,134, 156,104, 153,104, 151,105,
				   151,137};
int lvl8winj [] = {158,133, 163,133, 163,104, 158,104, 158,133};
int lvl8wink [] = {166,132, 170,132, 170,104, 166,104, 166,132};
int lvl8winl [] = {173,132, 178,132, 178,105, 176,104, 173,104, 173,132};
int lvl8winm [] = {181,132, 185,132, 185,107, 183,106, 181,106, 181,132};
int lvl8winn [] = {188,132, 193,132, 193,109, 191,108, 188,107, 188,132};
int lvl8wino [] = {195,132, 200,132, 200,112, 198,111, 195,109, 195,132};
int lvl8winp [] = {203,127, 207,127, 207,116, 205,115, 203,113, 203,127};
int lvl8winq [] = {210,132, 215,132, 215,122, 213,120, 210,118, 210,132};
int lvl8winr [] = {218,132, 220,132, 223,129, 218,124, 218,132};

int tail [] = {226,140, 226,137, 232,132, 238,132, 232,140, 226,140};
int runway [] = {239,146, 150,146, 150,151, 239,151, 239,146};

int plane [] = {153,144, 151,142, 151,140, 153,138, 155,136, 157,135,
				160,134, 163,133, 239,135, 236,138, 233,139, 226,144,
				153,144};
				
int tailwing [] = {220,134, 235,118, 244,118, 237,132, 232,132, 230,134,
				   220,134};
				   
int sidewing [] = {201,143, 201,141, 206,133, 206,128, 200,134, 192,139,
				   191,140, 191,143, 201,143};
				   
int frntwin [] = {156,137, 160,137, 160,135, 156,137};

int plnwina [] = {164,136, 164,137, 170,137, 170,136, 164,136};

int plnwinb [] = {173,136, 173,137, 190,137, 190,136, 173,136};

int plnwinc [] = {206,136, 206,137, 218,137, 218,136, 206,136};

int strp1 [] = {151,140, 151,142, 182,142, 182,142, 182,140, 151,140};

int strp2 [] = {203,140, 203,142, 225,140, 203,140};

int whl1 [] = {164,146, 164,148};
int whl2 [] = {197,146, 197,148};
int whl3 [] = {200,146, 200,148};



setcolor(0);	                                  setbkcolor(BLACK);
setfillstyle(8,8);



//COLORS
//level 1
setfillstyle(SOLID_FILL,15);
fillpoly(5,mapbox);
//fillpoly(11,border);
//setfillstyle(SOLID_FILL,12);
//fillpoly(5,box);
//setfillstyle(SOLID_FILL,5);
//fillpoly(5,sideborder);
setfillstyle(SOLID_FILL,2);
fillpoly(4,lvl1ptree1);
setfillstyle(SOLID_FILL,2);
fillpoly(5,lvl1ptree2);
setfillstyle(SOLID_FILL,2);
fillpoly(5,lvl1ptree3);
setfillstyle(SOLID_FILL,2);
fillpoly(8,lvl1ptree4);
setfillstyle(SOLID_FILL,2);
fillpoly(5,lvl1ptree5);
setfillstyle(SOLID_FILL,2);
fillpoly(6,lvl1ptree6);
setfillstyle(SOLID_FILL,2);
fillpoly(21,grncave);
setfillstyle(SOLID_FILL,8);
fillpoly(29,mncave);
setfillstyle(SOLID_FILL,2);
fillpoly(20,grncave2);
setfillstyle(SOLID_FILL,7);
fillpoly(20,lrock);
setfillstyle(SOLID_FILL,2);
fillpoly(18,grass1);
setfillstyle(SOLID_FILL,3);
fillpoly(18,lvl1door);
setfillstyle(SOLID_FILL,7);
fillpoly(13,rrock);
setfillstyle(SOLID_FILL,2);
fillpoly(30,grass2);
setfillstyle(SOLID_FILL,6);
fillpoly(43,lvl1trunk);
setfillstyle(SOLID_FILL,2);
fillpoly(44,lvl1leaves);

//level 2 colors
setfillstyle(SOLID_FILL,6);
fillpoly(5,benchl);
setfillstyle(SOLID_FILL,6);
fillpoly(13,bencht);
setfillstyle(SOLID_FILL,6);
fillpoly(16,lvl2trunk);
setfillstyle(SOLID_FILL,0);
fillpoly(13,lampstand);
setfillstyle(SOLID_FILL,14);
fillpoly(7,lamplight);
setfillstyle(SOLID_FILL,0);
fillpoly(6,lamptop);
setfillstyle(SOLID_FILL,2);
fillpoly(68,lvl2leaves);
setfillstyle(SOLID_FILL,6);
fillpoly(17,lvl2trunkb);
setfillstyle(SOLID_FILL,2);
fillpoly(47,lvl2leavesb);
drawpoly(2,dpconr);
drawpoly(2,dpconl);
drawpoly(2,dpstandr);
drawpoly(2,dpstandl);

//level 3 colors
setfillstyle(SOLID_FILL,7);
fillpoly(5,gwall);
setfillstyle(SOLID_FILL,13);
fillpoly(8,pwall);
setfillstyle(SOLID_FILL,6);
fillpoly(6,roof1);
setfillstyle(SOLID_FILL,6);
fillpoly(7,roof2);
setfillstyle(SOLID_FILL,6);
fillpoly(5,topperr);
setfillstyle(SOLID_FILL,6);
fillpoly(5,topperl);
setfillstyle(SOLID_FILL,6);
fillpoly(9,brownroof);
setfillstyle(SOLID_FILL,13);
fillpoly(8,attic);
setfillstyle(SOLID_FILL,6);
fillpoly(4,aroof);
setfillstyle(SOLID_FILL,4);
fillpoly(10,flag);
setfillstyle(SOLID_FILL,15);
fillpoly(9,doorway);
setfillstyle(SOLID_FILL,6);
fillpoly(5,lvl3door);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl3winar);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl3winbr);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl3wincr);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl3winal);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl3winbl);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl3wincl);
setfillstyle(SOLID_FILL,2);
fillpoly(7,lvl3grassa);
setfillstyle(SOLID_FILL,2);
fillpoly(8,lvl3grassb);
setfillstyle(SOLID_FILL,6);
fillpoly(17,lvl3trunk);
setfillstyle(SOLID_FILL,2);
fillpoly(61,lvl3leaves);
setfillstyle(SOLID_FILL,7);
fillpoly(5,lvl3path);
drawpoly(2,flagstand);
drawpoly(2,step1);
drawpoly(2,step2);
drawpoly(2,step3);
//level 4 colors
setfillstyle(SOLID_FILL,12);
fillpoly(17,station);
setfillstyle(SOLID_FILL,15);
fillpoly(5,detailbox);
setfillstyle(SOLID_FILL,4);
fillpoly(21,car);
setfillstyle(SOLID_FILL,7);
fillpoly(5,hlr);
setfillstyle(SOLID_FILL,7);
fillpoly(5,hll);
setfillstyle(SOLID_FILL,7);
fillpoly(5,ws);
setfillstyle(SOLID_FILL,8);
fillpoly(5,cardet);
setfillstyle(SOLID_FILL,0);
fillpoly(5,rt);
setfillstyle(SOLID_FILL,0);
fillpoly(5,lt);

//level 5 colors
setfillstyle(SOLID_FILL,6);
fillpoly(19,lvl5table1);
setfillstyle(SOLID_FILL,1);
fillpoly(6,box1);
setfillstyle(SOLID_FILL,3);
fillpoly(5,cyan1);
setfillstyle(SOLID_FILL,1);
fillpoly(9,box2);
setfillstyle(SOLID_FILL,3);
fillpoly(5,cyan2);
setfillstyle(SOLID_FILL,1);
fillpoly(7,box3);
setfillstyle(SOLID_FILL,3);
fillpoly(5,cyan3);
setfillstyle(SOLID_FILL,1);
fillpoly(8,box4);
setfillstyle(SOLID_FILL,3);
fillpoly(4,cyan4);
setfillstyle(SOLID_FILL,5);
fillpoly(7,tentmn);
setfillstyle(SOLID_FILL,6);
fillpoly(5,stand);
setfillstyle(SOLID_FILL,6);
fillpoly(5,lvl5tablea);
setfillstyle(SOLID_FILL,6);
fillpoly(5,lvl5tableb);
setfillstyle(SOLID_FILL,6);
fillpoly(5,lvl5tablec);
drawpoly(2,leg1);
drawpoly(2,leg2);
drawpoly(2,leg3);

//level 6 colors
setfillstyle(SOLID_FILL,8);
fillpoly(7,lvl6build1);
setfillstyle(SOLID_FILL,14);
fillpoly(5,lvl6win1);
setfillstyle(SOLID_FILL,6);
fillpoly(5,lvl6build2);
setfillstyle(SOLID_FILL,10);
fillpoly(5,lvl6detb);
setfillstyle(SOLID_FILL,14);
fillpoly(5,lvl6win2a);
setfillstyle(SOLID_FILL,14);
fillpoly(5,lvl6win2b);
setfillstyle(SOLID_FILL,8);
fillpoly(7,lvl6build3);
setfillstyle(SOLID_FILL,14);
fillpoly(5,lvl6win3);
setfillstyle(SOLID_FILL,12);
fillpoly(5,bboard);
setfillstyle(SOLID_FILL,7);
fillpoly(5,lvl6road);
setfillstyle(SOLID_FILL,0);
fillpoly(5,lvl6lighta);
setfillstyle(SOLID_FILL,0);
fillpoly(5,lvl6lightb);
drawpoly(6,lvl6aright);
drawpoly(6,lvl6aleft);
drawpoly(6,lvl6bright);
drawpoly(6,lvl6bleft);
drawpoly(2,bboardr);
drawpoly(2,bboardl);


//level 7 colors
setfillstyle(SOLID_FILL,12);
fillpoly(20,ptruck);
setfillstyle(SOLID_FILL,0);
fillpoly(5,lvl7win1);
setfillstyle(SOLID_FILL,8);
fillpoly(7,lvl7roof);
setfillstyle(SOLID_FILL,4);
fillpoly(21,rtruck);
setfillstyle(SOLID_FILL,7);
fillpoly(33,lining);
setfillstyle(SOLID_FILL,0);
fillpoly(20,lvl7tire1);
setfillstyle(SOLID_FILL,0);
fillpoly(19,lvl7tire2);
setfillstyle(SOLID_FILL,7);
fillpoly(5,lvl7win2);
setfillstyle(SOLID_FILL,7);
fillpoly(5,lvl7win3);
setfillstyle(XHATCH_FILL,9);
fillpoly(5,pcncblngkt);
setfillstyle(SOLID_FILL,6);
fillpoly(5,pcnctbl);
drawpoly(2,pcncleg1);
drawpoly(2,pcncleg2);
drawpoly(2,pcncleg3);
drawpoly(2,pcncleg4);

//level 8 colors
setfillstyle(SOLID_FILL,8);
fillpoly(27,watchtower);
setfillstyle(SOLID_FILL,11);
fillpoly(6,wtbar);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl8win1);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl8win2);
setfillstyle(SOLID_FILL,8);
fillpoly(62,airport);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8wina);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8winb);
setfillstyle(SOLID_FILL,11);
fillpoly(7,lvl8winc);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8wind);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8wine);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8winf);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8wing);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8winh);
setfillstyle(SOLID_FILL,11);
fillpoly(7,lvl8wini);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl8winj);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl8wink);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8winl);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8winm);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8winn);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8wino);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8winp);
setfillstyle(SOLID_FILL,11);
fillpoly(6,lvl8winq);
setfillstyle(SOLID_FILL,11);
fillpoly(5,lvl8winr);
setfillstyle(SOLID_FILL,7);
fillpoly(6,tail);
setfillstyle(SOLID_FILL,7);
fillpoly(5,runway);
setfillstyle(SOLID_FILL,15);
fillpoly(13,plane);
setfillstyle(SOLID_FILL,1);
fillpoly(7,tailwing);
setfillstyle(SOLID_FILL,7);
fillpoly(9,sidewing);
setfillstyle(SOLID_FILL,7);
fillpoly(4,frntwin);
setfillstyle(SOLID_FILL,7);
fillpoly(5,plnwina);
setfillstyle(SOLID_FILL,7);
fillpoly(5,plnwinb);
setfillstyle(SOLID_FILL,7);
fillpoly(5,plnwinc);
setfillstyle(SOLID_FILL,10);
fillpoly(6,strp1);
setfillstyle(SOLID_FILL,10);
fillpoly(4,strp2);
drawpoly(2,whl1);
drawpoly(2,whl2);
drawpoly(2,whl3);


int path1 [] = {388,395,170,394};
int path2 [] = {159,381,159,355};
int path3 [] = {172,343,305,343};
int path4 [] = {332,344,457,344};
int path5 [] = {469,330,469,237};
int path6 [] = {456,222,387,222};
int path7 [] = {359,222,201,222};

//borders
setfillstyle(SOLID_FILL, RED);
bar(2,0,641,62);	  
bar(1,1,62,481);
bar(1,461,641,481);
bar(617,1,641,481);


//level name

setfillstyle(SOLID_FILL, RED);
bar(178,0,474,71);
rectangle(178,0,474,71);



int j;
if(level==0){
setfillstyle(SOLID_FILL,RED);
circle(401,395,13);
floodfill(401, 395, BLACK);

for(i=0; i<3; i++)
{
bar(185,0,470,69);
delay(100);
settextstyle(10,0,2);
setcolor(WHITE);
setbkcolor(RED);
outtextxy(210,28, "LEVEL 1: HOUSE");
delay(100);
bar(185,0,470,69);
delay(100);
outtextxy(210,28, "LEVEL 1: HOUSE");
} //for blink
}

if(level==1){
    for(i=0; i<246; i+=6)
    {
    setfillstyle(SOLID_FILL, WHITE);
    circle(401-i,395,13);
    floodfill(401-i,395, WHITE);
    setfillstyle(SOLID_FILL, RED);
    circle(401-i,395,13);
    floodfill(401-i,395, BLACK);
    delay(1);
	}//motion
	
	for(i=0; i<3; i++)
{
bar(185,0,470,69);
delay(100);
settextstyle(10,0,2);
setcolor(WHITE);
setbkcolor(RED);
outtextxy(210,28, "LEVEL 2: PARK");
delay(100);
bar(185,0,470,69);
delay(100);
outtextxy(210,28, "LEVEL 2: PARK");
} //for blink
}

	if(level==2)
	{
	for(i=0; i<52; i+=1)
    {
    setfillstyle(SOLID_FILL, WHITE);
    circle(160,395-i,13);
    floodfill(160,395-i, WHITE);
    setfillstyle(SOLID_FILL, RED);
    circle(160,395-i,13);
    floodfill(160,395-i, BLACK);
      delay(1);
	} 


for(i=0; i<3; i++)
{
bar(185,0,470,69);
delay(100);
settextstyle(10,0,2);
setcolor(WHITE);
setbkcolor(RED);
outtextxy(210,28, "LEVEL 3: SCHOOL");
delay(100);
bar(185,0,470,69);
delay(100);
outtextxy(210,28, "LEVEL 3: SCHOOL");
} //for blink	
}//level
	if(level==3)
	{
		for(i=0; i<165; i+=5)
    {
    setfillstyle(SOLID_FILL, WHITE);
    circle(160+i,343,13);
    floodfill(160+i,343, WHITE);
    setfillstyle(SOLID_FILL, RED);
    circle(160+i,343,13);
    floodfill(160+i,343, BLACK);
      delay(1);
	}
	for(i=0; i<3; i++)
{
bar(185,0,470,69);
delay(100);
settextstyle(10,0,2);
setcolor(WHITE);
setbkcolor(RED);
outtextxy(210,28, "LEVEL 4: CAR SHOP");
delay(100);
bar(185,0,470,69);
delay(100);
outtextxy(210,28, "LEVEL 4: CAR SHOP");
} //for blink
	 } //if 
	
		
	
if(level==4)
		{
			for(i=0; i<156; i+=6)
    {
    setfillstyle(SOLID_FILL, WHITE);
    circle(320+i,343,13);
    floodfill(320+i,343, WHITE);
    setfillstyle(SOLID_FILL, RED);
    circle(320+i,343,13);
    floodfill(320+i,343, BLACK);
      delay(1);
	} 
		for(i=0; i<3; i++)
{
bar(185,0,470,69);
delay(100);
settextstyle(10,0,2);
setcolor(WHITE);
setbkcolor(RED);
outtextxy(210,28, "LEVEL 5: FOOD TRUCK");
delay(100);
bar(185,0,470,69);
delay(100);
outtextxy(210,28, "LEVEL 5: FOOD TRUCK");
} //for blink
	}//if 
	
	
	if(level==5)
	{
	for(i=0; i<122; i+=6)
    {
    setfillstyle(SOLID_FILL, WHITE);
    circle(470,343-i,13);
    floodfill(470,343-i, WHITE);
    setfillstyle(SOLID_FILL, RED);
    circle(470,343-i,13);
    floodfill(470,343-i, BLACK);
      delay(1);
	}
	
		for(i=0; i<3; i++)
{
bar(185,0,470,69);
delay(100);
settextstyle(10,0,2);
setcolor(WHITE);
setbkcolor(RED);
outtextxy(210,28, "LEVEL 6: MALL");
delay(100);
bar(185,0,470,69);
delay(100);
outtextxy(210,28, "LEVEL 6: MALL");
} //for blink

	 }//if 
	
	if(level==6){
	
		for(i=0; i<98; i+=2)
    {
    setfillstyle(SOLID_FILL, WHITE);
    circle(470-i,223,13);
    floodfill(470-i,223, WHITE);
    setfillstyle(SOLID_FILL, RED);
    circle(470-i,223,13);
    floodfill(470-i,223, BLACK);
      delay(1);
	} 
	
		for(i=0; i<3; i++)
{
bar(185,0,470,69);
delay(100);
settextstyle(10,0,2);
setcolor(WHITE);
setbkcolor(RED);
outtextxy(210,28, "LEVEL 7: FOOD SHOP");
delay(100);
bar(185,0,470,69);
delay(100);
outtextxy(210,28, "LEVEL 7: FOOD SHOP");
} //for blink
	
	}//if 
	
	if(level==7){

	
			for(i=0; i<189; i+=3)
    {
    setfillstyle(SOLID_FILL, WHITE);
    circle(375-i,223,13);
    floodfill(375-i,223, WHITE);
    setfillstyle(SOLID_FILL, RED);
    circle(375-i,223,13);
    floodfill(375-i,223, BLACK);
      delay(1);
	}
	
	
		for(i=0; i<3; i++)
{
bar(185,0,470,69);
delay(100);
settextstyle(10,0,2);
setcolor(WHITE);
setbkcolor(RED);
outtextxy(210,28, "LEVEL 8: AIRPORT");
delay(100);
bar(185,0,470,69);
delay(100);
outtextxy(210,28, "LEVEL 8: AIRPORT");
} //for blink
	 

	 }	 
setcolor(BLACK);

setfillstyle(SOLID_FILL,15);
circle(401,395,13);
setfillstyle(SOLID_FILL,15);
circle(160,395,13);
setfillstyle(SOLID_FILL,15);
circle(160,343,13);
setfillstyle(SOLID_FILL,15);
circle(320,343,13);//////
setfillstyle(SOLID_FILL,15);
circle(470,343,13);
setfillstyle(SOLID_FILL,15);
circle(470,223,13);
setfillstyle(SOLID_FILL,15);
circle(375,223,13);
setfillstyle(SOLID_FILL,15);
circle(188,223,13);


setlinestyle(DASHED_LINE,0,THICK_WIDTH);
drawpoly(2,path1);
drawpoly(2,path2);
drawpoly(2,path3);
drawpoly(2,path4);
drawpoly(2,path5);
drawpoly(2,path6);
drawpoly(2,path7);

//navigations
setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);
const int SPACE = 32;
char response, responseArr[100];
char *valid;


settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(10,455, "Press ESC to go back home");
//outtextxy(440,465, "Press TAB for hints");


setcolor(BLACK);
setbkcolor(WHITE);
	settextstyle(2,0,6);
	outtextxy(210, 410, "Press SPACE key to continue..");
balik:
setfillstyle(SOLID_FILL, WHITE);
bar(167,444,469,458);
	
response = getch();
sprintf(responseArr, "%c", response);
valid = strstr(validLetters, responseArr);
if (GetAsyncKeyState(VK_ESCAPE)){
			closegraph(); 
			startPage();}
else if(response==SPACE){
return;
}
else {
	settextstyle(2,0,5);
		outtextxy(180, 445, "WRONG KEY! PRESS ANY KEY TO ENTER AGAIN");
		getch();
		goto balik;
}//else


}//map


/*****************************************************************************FINISH*******************************************/
void finish()
{

int i;
setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);
//grizz

	int grizz[84]={214,100,220,96,227,92,235,88,242,84,251,81,262,77,273,74,294,69,309,67,
				   322,67,336,67,339,67,344,63,349,59,359,53,367,48,378,44,387,40,397,37,
				   407,34,419,31,430,30,440,30,450,28,464,27,478,27,486,27,499,27,513,29,
				   526,30,537,32,547,32,555,35,568,38,585,42,597,46,613,50,627,56,639,62,
				   639,367,208,345};
	int grizzEar[44]={382,39,378,36,375,32,375,29,379,24,385,22,384,20,390,17,397,14,406,11,
					  417,10,429,7,440,7,451,8,461,11,469,14,471,19,473,23,472,25,472,27,
					  474,36,396,54};
	int grizzEye1[36]={590,88,587,88,583,87,579,88,576,89,574,92,571,94,569,97,568,100,570,104,
					   574,105,578,105,582,104,586,102,589,100,591,97,591,93,591,91};
	int grizzEye2[34]={441,70,441,67,440,65,438,64,434,63,431,63,428,65,424,67,421,69,419,72,
					   418,76,419,78,423,79,427,80,431,79,435,76,439,74};
	int grizzMouth[74]={495,153,492,152,487,151,480,149,474,147,467,147,460,146,452,146,445,147,438,148,
						432,151,424,156,418,160,416,168,415,172,418,177,425,181,433,185,442,190,459,195,
						474,198,490,200,504,201,531,197,545,195,558,189,575,182,584,171,589,159,587,149,
						581,147,572,143,561,140,550,139,540,139,524,143,504,151};
	int grizzTeeth1[10]={462,147,462,153,464,161,470,182,473,197};
	int grizzTeeth2[10]={531,140,537,148,539,166,540,179,538,195};
	int grizzNose[32]={498,111,491,105,482,102,473,99,462,98,450,97,439,98,432,99,432,102,435,104,
					   442,108,451,113,462,115,475,116,487,117,497,116};
	int grizzNose2[24]={476,94,468,91,460,90,454,90,446,89,438,89,431,89,424,89,419,90,412,91,404,92,400,93};
	int grizzEB1[14]={596,53,599,55,605,57,608,60,611,63,611,67,612,71};
	int grizzEB2[16]={454,40,452,39,447,38,443,38,437,40,432,44,427,47,426,51};
	int grizzArm[80]={639,203,632,203,625,203,619,203,613,203,605,204,596,205,587,205,578,207,568,207,
					  553,210,542,210,529,212,519,213,509,216,497,218,486,219,478,222,466,225,454,230,
					  449,235,445,241,447,248,453,251,463,253,473,253,484,255,486,259,486,267,491,275,
					  496,281,503,286,513,294,524,298,537,300,548,303,565,304,585,307,600,307,639,307};
					  
	//background
	setfillstyle(SOLID_FILL, CYAN);
	bar(1,1,640,170);
				   
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BROWN);
	fillpoly(22, grizzEar);
	fillpoly(42, grizz);
	fillpoly(40, grizzArm);

	setfillstyle(SOLID_FILL,WHITE);
	fillpoly(37, grizzMouth);
	
	setfillstyle(SOLID_FILL, BLACK);
	fillpoly(18, grizzEye1);
	fillpoly(17, grizzEye2);
	drawpoly(5,grizzTeeth1);
	drawpoly(5,grizzTeeth2);
	fillpoly(16, grizzNose);
	drawpoly(12, grizzNose2);
	drawpoly(7, grizzEB1);
	drawpoly(8, grizzEB2);
	
	   
//icebear

int icebear[92]={1,151,12,151,17,151,27,154,33,156,37,156,40,154,50,150,55,148,65,143,
				73,140,86,134,101,131,116,126,127,123,139,121,153,119,167,118,183,118,200,121,
				213,124,225,128,236,132,250,138,269,149,283,156,294,162,304,162,316,163,327,164,
				337,167,348,170,361,175,373,183,385,191,395,201,404,212,410,225,416,237,418,251,
				418,262,414,272,411,282,402,306,322,479,1,479};	
				
int ibEar[36]={149,120,149,115,150,110,156,103,162,98,168,95,178,94,189,94,197,94,203,94,
				211,97,217,101,224,106,228,111,228,119,228,124,228,131,227,139};
int ibEye1[38]={117,193,112,192,109,191,105,191,103,191,100,192,98,195,100,197,103,201,106,204,
				109,205,113,207,115,207,118,207,121,207,125,205,125,201,122,198,120,195};
				
int ibEye2[32]={230,178,228,176,226,173,225,170,226,167,229,164,233,164,237,166,239,168,241,170,
				245,173,245,176,243,179,240,181,236,182,232,182};
int ibMouth[12]={258,273,262,273,266,271,271,268,280,267,288,265};
int ibNose[40]={272,209,273,205,271,202,268,200,263,200,258,200,251,201,244,203,238,205,230,208,
				225,212,219,214,216,219,216,222,221,225,230,227,238,227,251,223,261,218,267,216};
int ibNose1[28]={214,198,218,198,222,197,227,196,234,194,242,192,252,191,261,189,273,189,284,189,
				 292,189,301,191,308,193,312,195};
			   
				
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(18, ibEar);
	fillpoly(46, icebear);
	
	setfillstyle(SOLID_FILL,BLACK);
	fillpoly(19, ibEye1);
	fillpoly(16, ibEye2);
	drawpoly(6, ibMouth);
	fillpoly(20, ibNose);
	drawpoly(14, ibNose1);
	
	       
       
//panda       
    int panda[126]={535,478,558,467,575,457,586,447,597,437,607,420,611,407,612,395,610,378,593,356,
			   581,346,559,337,541,332,524,329,506,328,485,331,478,331,474,331,466,325,460,320,
			   447,313,434,310,417,307,404,306,392,306,381,304,365,305,350,305,331,307,309,307,
			   289,312,277,313,264,317,252,318,236,323,224,328,209,332,193,336,182,343,171,347,
			   163,349,154,355,145,359,138,364,134,367,124,359,113,355,97,353,83,351,73,351,
			   57,355,47,359,39,365,30,371,24,380,20,391,24,403,35,413,50,424,97,436,
			   114,458,126,476,130,479};
	int panE1[42]={142,372,133,367,120,358,109,354,100,352,84,352,67,352,47,359,36,364,24,374,
					20,385,23,402,34,415,49,421,60,428,74,431,88,431,104,428,128,409,143,397,149,381};
	int panE2[40]={376,303,381,298,387,294,397,290,407,287,416,284,429,282,437,282,446,281,452,281,
				   464,284,472,286,481,291,489,296,498,303,501,313,500,321,497,328,485,333,479,338};
int panEye1[56]=  {243,356,225,356,212,360,205,360,199,363,192,368,182,375,176,381,168,392,166,406,
				   172,418,180,427,191,432,204,438,220,439,232,439,252,437,263,433,277,429,289,421,
				   297,414,300,406,301,397,301,390,299,382,294,374,289,369,278,362};
int panEye2[64]=  {460,376,452,376,445,378,432,378,420,378,406,376,396,375,388,373,379,370,371,368,
				   361,365,353,361,345,357,340,352,337,346,337,340,341,335,349,329,359,322,375,319,
				   396,319,417,320,431,321,448,325,461,332,473,334,482,342,488,346,491,356,489,364,
				   480,369,474,374};
int panBody[18]=   {572,341,585,326,595,316,605,307,616,296,627,288,638,278,637,475,521,475};
int panNose[40]=   {406,384,402,385,397,386,390,390,383,392,376,396,370,400,365,403,365,408,368,414,
					372,414,381,414,391,414,402,412,410,410,426,406,434,400,435,394,434,389,428,384};
int panMouth[54]=  {439,461,434,463,429,467,423,468,411,472,400,472,394,472,382,471,369,470,362,470,
					351,469,346,464,346,460,347,456,352,453,360,450,367,450,375,450,381,450,388,452,
					398,454,404,454,411,453,421,453,428,453,436,453,439,458};
int panT1[12]={372,470,376,464,377,460,378,457,378,454,378,451};
int panT2[10]={413,454,412,459,412,464,410,468,407,470};
int panEyeA[24]= {228,367,225,367,221,367,220,371,220,373,227,376,234,380,238,382,242,381,246,380,
				247,377,239,371};
int panEyeB[18]={375,326,373,330,387,340,395,340,398,340,398,335,392,331,386,328,381,326};
int panEyeEB1[28]={192,366,196,364,202,363,207,361,211,359,214,356,217,352,219,349,222,349,223,352,
				   220,357,215,361,208,364,198,367};
int panEyeEB2[28]={384,321,377,322,370,322,363,322,355,322,345,322,337,322,332,320,335,323,341,325,
				   351,325,357,325,365,326,375,324};
int panNose2[20]= {380,386,387,384,398,381,409,380,420,379,429,378,440,378,449,379,461,382,478,387};

	
	setfillstyle(SOLID_FILL, DARKGRAY);
	fillpoly(20, panE2);
	fillpoly(9, panBody);
	
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(63, panda);
	fillpoly(27, panMouth);
	
	setfillstyle(SOLID_FILL, DARKGRAY);
	fillpoly(21, panE1);
	fillpoly(28, panEye1);
	fillpoly(32, panEye2);
	
	setfillstyle(SOLID_FILL, BLACK);
	fillpoly(20, panNose);
	drawpoly(6, panT1);
	drawpoly(5, panT2);
	fillpoly(12, panEyeA);
	fillpoly(9, panEyeB);
	fillpoly(14, panEyeEB1);
	fillpoly(14, panEyeEB2);
	drawpoly(10, panNose2);

	setfillstyle(SOLID_FILL, RED);
	bar(630,0,640,480);
	bar(1,0,10,480);
	bar(0,1,640,35);
	bar(0,473,640,480);
  
  //navigations
const int SPACE = 32;
char response, responseArr[100];
char *valid;
    
 	if(level>=0 && level<7){
      for(i=0; i<161; i+=5)
    {
    settextstyle(2,0,9);
	setcolor(WHITE);
	setbkcolor(RED);	
    outtextxy(0+i,262, "  LEVEL ");
    delay(1);
    }	
    
    for(i=0; i<345; i+=5)
    {
    settextstyle(2,0,9);
	setcolor(WHITE);
	setbkcolor(RED);	
    outtextxy(634-i,262, "COMPLETE!  ");
    delay(1);} 
	
	
	}//if level
    

	else if(level==7	 || logoNumber==36){
			  for(i=0; i<70; i+=2)
    {
    settextstyle(2,0,9);
	setcolor(WHITE);
	setbkcolor(RED);	
    outtextxy(0+i,262, "  THANK YOU ");
    delay(1);
    }	
    
    for(i=0; i<335; i+=5)
    {
    settextstyle(2,0,9);
	setcolor(WHITE);
	setbkcolor(RED);	
    outtextxy(634-i,262, " FOR PLAYING!  ");
    delay(1);}

balikbalik:
setfillstyle(SOLID_FILL, WHITE);
bar(167,444,469,458);
setcolor(BLACK);
setbkcolor(WHITE);
	settextstyle(2,0,6);
	outtextxy(210, 410, "Press SPACE key to continue..");
	
	settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(10,455, "Press ESC to go back home");

response = getch();
sprintf(responseArr, "%c", response);
if(response==SPACE){
	level=0;
	logoNumber=0;
	
    closegraph();
    startPage();}
    
else if (GetAsyncKeyState(VK_ESCAPE)){
			closegraph(); 
			startPage();
			}

else {
	settextstyle(2,0,5);
		outtextxy(180, 445, "WRONG KEY! PRESS ANY KEY TO ENTER AGAIN");
		getch();
		goto balikbalik;
}//else


	}//else if finish game
	
	
	
//navigations
setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);


settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(10,455, "Press ESC to go back home");
//outtextxy(440,465, "Press TAB to go back home");

setcolor(BLACK);
setbkcolor(WHITE);
	settextstyle(2,0,6);
	outtextxy(210, 410, "Press SPACE key to continue..");
balik:
setfillstyle(SOLID_FILL, WHITE);
bar(167,444,469,458);
	
response = getch();
sprintf(responseArr, "%c", response);
valid = strstr(validLetters, responseArr);
if (GetAsyncKeyState(VK_ESCAPE)){
			closegraph(); 
			startPage();
			}

else if(response==SPACE){
return;
}
else {
	settextstyle(2,0,5);
		outtextxy(180, 445, "WRONG KEY! PRESS ANY KEY TO ENTER AGAIN");
		getch();
		goto balik;
}//else

   }//finish


/*****************************************************************LEVEL ONE*********************************************/

void level_one ()
{



	int treeBranch[126] = {10,440,123,458,122,452,89,434,66,420,60,399,66,394,82,392,102,392,109,393,
				 159,388,169,388,174,384,169,380,159,380,57,381,44,312,41,284,38,226,46,220,
				  51,217,58,216,66,216,114,213,122,211,143,212,164,212,160,201,139,203,56,204,
				  37,203,37,97,43,93,52,90,66,88,78,88,93,92,100,93,110,97,123,100,137,102,146,104,156,103,166,102,172,98,
				  182,99,194,106,200,104,190,100,162,97,150,96,133,96,106,89,146,84,154,82,176,85,186,85,182,72,168,72,74,71,73,77,11,76,10,308};
	int treeLeavesA[104] = {165,74,160,77,154,71,157,67,148,69,146,63,150,59,154,52,160,51,165,47,
						170,45,174,48,180,47,185,45,189,48,192,53,198,49,204,48,209,48,214,49,
						219,47,224,55,229,53,230,51,234,55,240,52,245,50,250,49,254,55,252,58,
						249,63,255,72,254,79,260,79,264,83,264,89,258,93,249,96,242,100,235,95,
						227,98,218,97,212,97,208,92,208,99,202,102,195,97,188,97,182,92,175,90,
						174,82,171,76};
	int treeLeavesB[72] = {154,190,148,186,143,187,138,183,132,184,132,190,125,187,122,191,126,195,121,198,
						 120,202,126,202,130,206,136,205,142,208,141,214,146,216,149,222,153,223,157,219,
						 161,223,164,223,168,218,172,222,178,219,178,224,184,222,195,221,200,218,197,198,
						 198,186,186,191,176,188,169,188,163,185,160,190};
	int treeLeavesC[42] = {212,372,197,377,194,372,186,373,176,373,168,370,161,374,158,379,163,382,160,387,
						   161,393,165,397,170,396,170,402,176,404,182,404,184,409,189,411,193,408,199,409,
						   206,410};
	int grassA [100]		= {11,440,15,442,15,436,18,429,21,446,21,439,26,438,32,437,29,442,34,444,
						   41,444,47,446,46,439,45,433,53,444,58,443,66,439,61,448,66,448,71,443,
						   71,449,77,449,92,450,101,452,105,448,106,456,115,453,124,454,124,447,121,441,
						   130,446,136,440,141,437,138,445,138,450,148,442,142,449,140,456,146,454,153,453,
						   149,460,164,458,169,461,160,462,153,468,165,466,158,470,90,462,52,461,10,458};
	int grassbg [28] ={10,419,447,410,464,403,478,400,492,395,512,390,524,386,541,384,555,382,568,381,588,380,628,380,629,471,10,471};
	int treeBranchB[90] ={630,453,576,453,584,447,594,444,605,441,617,437,624,429,629,422,629,407,609,405,
					  598,406,587,406,562,403,555,402,559,397,566,397,629,398,630,288,623,284,616,283,
					  605,282,588,280,575,281,531,279,519,275,521,269,542,270,576,272,600,272,629,270,
					  630,155,630,146,602,143,562,141,546,140,532,139,510,138,506,130,525,131,546,133,
					  566,133,611,130,629,127,639,127,639,452};
	int treeBLeavesA [60] ={512,133,519,133,524,134,527,129,533,129,530,123,528,117,522,116,514,113,507,115,
						  500,115,495,119,487,115,486,112,480,117,475,114,468,114,467,120,459,117,456,121,
						  458,148,463,153,468,147,472,151,479,151,489,149,490,142,496,150,503,147,508,144};
	int treeBLeavesB[60]   = {520,290,531,285,532,278,534,273,541,276,545,272,552,269,549,262,544,255,536,255,
							530,254,524,252,520,258,513,255,504,253,496,257,490,257,480,257,476,255,474,263,
							476,269,470,272,466,279,470,284,472,289,482,289,488,291,497,287,504,291,513,291};
	int bp1A[36]= 		   {523,380,535,370,544,358,553,347,568,339,584,332,575,332,566,332,559,332,555,334,
							548,333,542,336,536,340,532,344,529,352,529,361,529,368,526,375};
	int bp1B[34]=		   	   {555,345,567,337,577,333,588,332,594,337,598,344,604,355,608,369,607,377,602,381,
							599,385,595,389,580,385,583,377,578,367,571,359,564,352};
	int bp1C[26]=				   {612,373,608,371,602,372,598,376,598,384,598,391,600,397,608,399,615,395,620,390,
								625,380,626,374,620,371};
	int bp1D[44]=				{607,326,598,312,588,302,574,294,566,291,549,286,553,295,560,308,571,322,576,330,
							 596,374,582,383,576,387,592,388,629,392,629,317,620,321,622,313,620,296,616,303,
							 614,309,614,317};
	int bp1E[16]=	{604,350,606,333,607,324,612,316,620,309,612,335,612,347,606,364};
	int bp1detailA[10]={570,302,583,310,591,315,605,349,589,323};
	int bp1detailB[10]={554,333,544,340,534,363,549,342,563,333};
	int bp2A[40]= {56,373,66,366,74,363,82,362,90,362,99,363,109,360,116,360,124,369,127,376,128,390,126,401,127,411,131,419,124,418,110,407,103,395,94,380,87,374,78,368};
	int bp2B[22]={63,417,70,404,79,394,94,385,91,377,84,372,77,369,69,369,63,373,59,377,58,390};
	int bp2C[34]={61,408,78,400,85,396,95,394,112,395,125,404,132,413,139,424,150,434,137,434,122,429,106,422,97,423,98,431,100,438,90,433,54,424};
	int bp2D[14]={81,361,90,347,79,350,68,354,61,359,50,375,56,379};
	int grassbg2[124]={46,323,54,323,61,328,65,331,70,322,82,322,85,331,92,339,96,345,103,344,
					114,339,128,339,135,343,138,334,141,327,148,326,157,326,158,334,162,340,169,339,
					170,331,179,331,179,338,184,345,190,341,196,332,204,332,225,337,463,335,470,330,
					482,331,484,322,488,316,498,314,503,317,503,309,507,305,515,305,516,296,516,290,
					524,291,527,298,534,303,538,292,546,289,548,297,559,292,565,290,573,291,574,297,
					579,292,587,297,592,299,596,294,600,291,608,290,611,295,612,301,619,297,631,297,
					628,374,48,401};
	int grassbg3[60]={42,349,58,327,74,319,84,312,80,297,82,290,95,294,100,297,99,285,105,285,
					110,293,116,293,122,293,124,287,130,285,138,289,144,289,152,291,159,290,163,284,
					171,277,180,278,184,284,190,284,201,279,462,271,473,267,496,268,632,279,631,376};
					
	int grassbg4[74]={76,348,78,339,93,351,98,347,108,342,123,342,129,349,135,346,137,336,141,328,
					150,327,160,331,163,342,171,348,172,340,181,331,194,335,196,344,471,379,478,373,
					482,366,498,366,496,359,500,349,513,345,516,354,524,342,532,340,536,330,544,326,
					552,322,552,330,562,328,571,328,628,328,629,409,74,436};
	int mpA[38]={36,247,48,253,59,267,56,279,61,283,67,273,77,288,76,263,82,244,118,197,120,213,115,221,118,235,127,255,114,267,122,264,127,260,139,298,48,344};
	int mpB[8]={86,267,99,296,100,261,98,288};
//background
setfillstyle(SOLID_FILL, CYAN);
bar(12,32,632,474);		

//magenta plant
setfillstyle(SOLID_FILL, MAGENTA);
fillpoly(19, mpA);
setfillstyle(SOLID_FILL, DARKGRAY);
fillpoly(4,mpB);

//grass bg			

setfillstyle(SOLID_FILL, GREEN);
fillpoly(30, grassbg3);
setfillstyle(SOLID_FILL, LIGHTGREEN);
fillpoly(62, grassbg2);
setfillstyle(SOLID_FILL, GREEN);
fillpoly(37, grassbg4);

setfillstyle(SOLID_FILL, LIGHTGREEN);
fillpoly(14, grassbg);

//blueplant 1&2
setfillstyle(SOLID_FILL, LIGHTBLUE);
fillpoly(22, bp1D);
fillpoly(17,bp1B);
fillpoly(18,bp1A);
fillpoly(13,bp1C);
fillpoly(8,bp1E);
fillpoly(20,bp2A);
fillpoly(11,bp2B);
fillpoly(17, bp2C);
fillpoly(7, bp2D);
setfillstyle(SOLID_FILL, DARKGRAY);
fillpoly(5,bp1detailA);
fillpoly(5,bp1detailB);

//trees
setfillstyle(SOLID_FILL, BROWN);
fillpoly(63, treeBranch);
fillpoly(45, treeBranchB);		
setfillstyle(SOLID_FILL, GREEN);
fillpoly(52, treeLeavesA);	
fillpoly(36, treeLeavesB);	
fillpoly(21, treeLeavesC);
fillpoly(30, treeBLeavesA);
fillpoly(30, treeBLeavesB);

//grass
fillpoly(50, grassA);


//white box
setfillstyle(SOLID_FILL, WHITE);
fillpoly(4,box);
drawpoly(20, roundbox);	

//borders
setfillstyle(SOLID_FILL, RED);
bar(0,471,640,480);	  
bar(0,0,12,480);
bar(627,0,640,480);
bar(0,0,640,31);
fillpoly(4, logonum);
fillpoly(4, levelnum);

settextstyle(2,0,4);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(15,455, "Press TAB for hints");
outtextxy(470,455, "Press ESC to go back home");

}
/*****************************************************LOGO ONE*******************************************/
void logo_one ()
{

int m[40]={267,263,320,178,347,179,326,219,339,217,326,252,366,210,352,209,378,176,388,188,
		   394,195,398,205,372,288,344,287,355,247,313,288,309,249,274,299,261,286,257,270};
setcolor(LIGHTRED);
setfillstyle(SOLID_FILL, LIGHTRED);
circle(331,232,72);	
floodfill(331,232, LIGHTRED);

setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
fillpoly(20, m);
//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "1");
settextstyle(2,0,10);
outtextxy(255,8,"1 of 1");		
 } //function

/*****************************LEVEL TWO*******************************************************************/

void level_two()
{
	int treeG1[96]={0,211,3,215,5,215,9,213,12,213,15,213,23,211,25,209,29,213,37,211,
					43,207,43,205,48,207,55,207,61,203,67,203,77,195,77,189,83,184,86,177,
					86,172,93,178,113,177,119,172,123,164,135,163,134,154,134,143,135,139,136,133,
					135,125,139,115,136,104,134,89,125,77,120,79,125,64,122,60,129,47,125,40,
					123,36,121,32,119,19,113,12,107,8,103,6,99,3,1,0};
	int grassA[328]={0,146,137,137,141,133,145,130,149,130,151,135,152,128,155,127,157,128,159,126,
					163,124,166,126,170,119,173,126,176,130,175,136,177,138,187,142,189,138,198,139,
					203,128,208,124,208,119,210,112,214,111,220,114,226,112,239,107,247,107,257,96,
					265,104,273,104,278,104,279,109,282,102,292,107,299,100,314,100,325,104,332,102,
					345,103,351,110,349,120,351,127,363,129,371,146,370,156,373,141,383,139,390,140,
					393,142,387,128,409,134,413,142,415,138,421,138,426,148,439,154,438,147,444,145,
					452,144,451,138,458,133,469,142,470,148,472,152,478,152,483,167,489,155,495,150,
					505,147,511,150,513,158,525,145,539,144,613,170,619,172,619,174,619,177,625,176,
					630,166,637,160,639,292,631,292,628,287,626,284,627,276,623,283,622,288,615,288,
					613,288,605,284,603,280,601,275,597,270,599,266,593,269,590,262,586,260,584,258,
					579,261,561,254,557,254,553,257,549,254,543,254,538,256,531,250,529,255,521,255,
					515,254,513,251,511,249,508,248,499,253,491,249,484,254,477,254,441,252,430,252,
					420,245,417,249,409,250,405,255,391,252,391,257,391,248,380,246,374,249,373,242,
					367,242,362,243,359,243,357,237,354,236,347,238,343,245,335,245,333,250,323,248,
					313,246,291,246,267,246,247,242,203,244,193,244,187,248,177,248,171,251,167,250,
					159,248,151,248,143,239,137,245,129,247,119,247,101,250,79,248,69,247,61,252,
					59,245,34,246,14,245,3,248};
	int treeG2[122]={579,197,587,192,592,185,595,186,607,176,613,170,615,164,614,159,617,144,615,134,
					609,129,613,128,619,108,619,94,619,89,619,75,622,70,618,56,617,52,611,37,
					607,33,601,32,595,28,589,28,585,28,581,24,577,22,573,24,563,30,560,30,
					555,32,553,37,551,40,550,43,544,50,542,52,541,59,545,64,541,70,539,84,
					535,89,534,93,534,95,527,104,527,120,527,122,520,128,518,138,518,150,517,158,
					517,162,514,166,520,176,524,182,538,189,544,192,549,187,555,195,561,195,565,195,
					574,198};
	int grassB[128]={1,319,6,317,7,321,13,311,17,312,21,315,28,311,29,316,33,315,40,319,
					41,326,44,326,47,322,52,323,55,325,59,325,61,326,71,327,75,331,77,339,
					78,341,79,345,83,345,86,351,91,353,95,353,99,353,105,359,108,353,111,367,
					113,370,117,370,119,382,121,387,125,395,129,392,132,397,139,399,139,411,144,414,
					138,425,135,431,125,436,111,428,105,428,106,421,101,429,95,431,91,439,86,440,
					80,441,70,443,57,433,59,433,54,437,47,438,41,437,32,440,27,441,20,439,
					18,443,15,444,11,437,2,431};
	int treeB1[50]={43,198,45,218,53,205,59,191,67,194,56,216,53,222,46,230,45,238,43,245,
					44,258,45,277,47,294,49,310,52,320,55,324,66,338,9,336,19,310,21,290,
					23,267,24,258,24,244,24,222,22,206};
	int treeB2[26]={568,194,570,206,569,218,567,228,564,244,561,256,560,264,560,268,554,271,577,273,
					577,255,575,232,579,192};
	int ssA[28]   ={593,325,417,212,414,209,411,209,406,209,402,211,402,216,407,221,573,333,579,337,
					585,337,589,335,594,333,595,330}; //ss=seesaw
	int ssB[22]   ={597,330,595,336,593,339,587,343,581,343,574,339,404,224,401,221,401,215,403,213,
					413,213};	
	int ssC[28]   ={470,311,470,304,470,297,471,290,471,281,473,272,475,268,478,266,481,265,484,265,
					487,268,490,274,490,282,491,314};		
	int ssD[14]   ={483,263,489,265,493,269,494,276,496,290,495,313,481,311};	
	int ssE[18]   ={500,298,500,265,501,262,505,260,507,258,510,258,515,261,517,265,519,304};
int ssHandle[24]=  {561,285,555,289,553,289,551,285,553,282,575,276,578,278,578,281,569,285,558,312,
					556,314,553,311};
int slide1[78]=	   {302,154,295,155,284,164,279,169,274,173,266,180,259,192,251,205,245,217,237,229,
					230,242,224,257,217,269,212,279,205,291,200,299,193,308,187,315,181,323,174,329,
					167,333,163,335,161,349,169,347,176,344,183,338,193,329,203,315,213,303,219,293,
					224,284,229,277,232,265,240,253,245,237,255,223,259,213,267,201,273,195};
int slide2[22]=		{159,349,141,337,159,327,164,322,171,317,180,307,187,299,193,285,206,269,224,277,
					 194,331};
int slide3[26]=		{201,251,195,260,191,270,187,277,181,285,175,294,169,301,159,311,152,315,146,320,
					 142,336,147,342,216,264};
int boxA[14]=		{230,385,221,410,309,479,447,480,536,399,526,377,382,479};
int boxB[16]=		{230,383,243,385,381,467,511,379,524,377,533,393,381,480,228,405};
int boxLand[50]=    {381,471,251,393,368,347,371,344,377,344,383,350,390,355,394,355,403,355,411,355,
					 417,359,421,361,425,361,431,362,437,367,442,369,447,369,451,371,453,372,463,371,
					 474,375,479,381,486,379,496,381,506,387};
int boxC[8]=		{525,377,509,379,371,337,370,330};
int boxD[8]=		{370,336,511,379,498,388,370,353};
	setcolor(BLACK);
	
	setfillstyle(SOLID_FILL,CYAN);
	bar(0,1,638,183);
	
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	bar(0,243,638,478);
	
	setfillstyle(SOLID_FILL, GREEN);
	fillpoly(164, grassA);
	
	setfillstyle(SOLID_FILL, BROWN);
	fillpoly(25, treeB1);
	fillpoly(13, treeB2);
	
	setfillstyle(SOLID_FILL, GREEN);
	fillpoly(48, treeG1);
	fillpoly(61, treeG2);
	fillpoly(64, grassB);
	
	setfillstyle(SOLID_FILL, YELLOW);
	fillpoly(9, ssE);
		
	setfillstyle(SOLID_FILL, BLUE);
	fillpoly(11, ssB);
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	fillpoly(14, ssA);
	
	setfillstyle(SOLID_FILL, YELLOW);
	fillpoly(7, ssD);
	fillpoly(14, ssC);

	setfillstyle(SOLID_FILL, BLUE);
	fillpoly(12, ssHandle);
	
	setfillstyle(SOLID_FILL, MAGENTA);
	fillpoly(13, slide3);
	
	setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	fillpoly(11, slide2);

	setfillstyle(SOLID_FILL, MAGENTA);
	fillpoly(39, slide1);
	
	setfillstyle(SOLID_FILL, RED);
	fillpoly(8, boxD);
	setfillstyle(SOLID_FILL, BROWN);
	fillpoly(25, boxLand);
	
	setfillstyle(SOLID_FILL, LIGHTRED);
	fillpoly(8, boxB);
	fillpoly(7, boxA);
	fillpoly(4, boxC);
	
//white box
setfillstyle(SOLID_FILL, WHITE);
fillpoly(4,box);
drawpoly(20, roundbox);	

//borders
setfillstyle(SOLID_FILL, RED);
bar(0,471,640,480);	  
bar(0,0,12,480);
bar(627,0,640,480);
bar(0,0,640,31);
fillpoly(4, logonum);
fillpoly(4, levelnum);

settextstyle(2,0,4);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(15,455, "Press TAB for hints");
outtextxy(470,455, "Press ESC to go back home");
	
}//level two


/*****************************************************************LEVEL THREE*************************************************/
void level_three(){
	
setcolor(BLACK);	

setfillstyle(SOLID_FILL, LIGHTBLUE);
bar(2,292,639,479);
int wallRight[8]={636,0,584,2,586,224,640,235};
setfillstyle(SOLID_FILL, LIGHTGRAY);
bar(57,0,4,319);
rectangle(57,0,4,319);
bar(55,6,585,296);
rectangle(55,6,585,296);
fillpoly(4, wallRight);

int lg1[8]={55,209,1,222,2,320,58,307};
int lg2[10]={585,207,596,210,639,223,638,328,581,296};
setfillstyle(SOLID_FILL, LIGHTGREEN);
fillpoly(4, lg1);
fillpoly(5, lg2);
bar(55,209,585,301);
rectangle(55,209,585,301);

setfillstyle(SOLID_FILL,BROWN);
bar(519,214,120,37);

setfillstyle(SOLID_FILL, GREEN);
bar(125,42,516,208);
bar(199,288,586,302);
rectangle(199,288,586,302);

int chair[36]={100,244,82,228,84,218,85,212,88,205,94,200,98,197,105,195,113,194,123,194,
				130,196,135,201,140,206,142,214,143,220,143,227,143,232,132,241};
setfillstyle(SOLID_FILL, BLUE);
fillpoly(18, chair);

int table1[10] ={0,245,24,236,220,238,193,264,2,264};
int table2[10] ={186,273,187,355,213,318,214,259,196,275};
setfillstyle(SOLID_FILL, BROWN);
fillpoly(5, table1);
fillpoly(5, table2);
bar(0,272,187,357);
rectangle(1,279,181,348);
bar(1,262,196,274);
rectangle(1,262,196,274);


int cabinetA[12]={564,131,546,131,527,134,526,299,546,312,560,313};

setfillstyle(SOLID_FILL, RED);
fillpoly(6, cabinetA);
bar(600,131,547,312);
rectangle(600,131,547,312);

setfillstyle(SOLID_FILL, LIGHTRED);
bar(554,137,593,170);
rectangle(554,137,593,170);
bar(554,178,594,215);
rectangle(554,178,594,215);
bar(554,224,594,263);
rectangle(554,224,594,263);
bar(554,273,594,303);
rectangle(554,273,594,303);

setfillstyle(SOLID_FILL, BROWN);
bar(568,151,584,156);
rectangle(568,151,584,156);
bar(566,192,584,198);
rectangle(566,192,584,198);
bar(566,240,583,246);
rectangle(566,240,583,246);
bar(568,287,584,293);
rectangle(568,287,584,293);


	//white box
setfillstyle(SOLID_FILL, WHITE);
fillpoly(4,box);
drawpoly(20, roundbox);	

//borders
setfillstyle(SOLID_FILL, RED);
bar(0,471,640,480);	  
bar(0,0,12,480);
bar(627,0,640,480);
bar(0,0,640,31);
fillpoly(4, logonum);
fillpoly(4, levelnum);

settextstyle(2,0,4);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(15,455, "Press TAB for hints");
outtextxy(470,455, "Press ESC to go back home");
}//level three

/*****************************************************LEVEL FOUR*************************/
void level_four(){
	
int cloudA[328]={0,155,4,155,9,153,13,154,21,157,25,161,30,168,32,175,33,175,34,172,
				38,171,44,171,46,172,48,172,46,170,46,167,46,163,46,158,50,148,56,142,
				63,139,71,136,82,135,89,140,93,148,94,157,94,160,97,152,106,152,113,154,
				107,148,112,142,118,141,129,145,131,153,130,156,134,152,140,153,144,161,142,171,
				147,164,153,164,157,166,160,166,165,172,167,178,169,174,164,163,164,153,168,146,
				174,142,186,142,190,141,193,144,196,138,200,137,207,135,216,135,221,136,226,144,
				226,154,224,163,228,159,235,158,242,161,246,168,246,176,248,172,253,172,257,172,
				260,176,262,180,268,172,278,169,289,173,292,176,295,174,292,169,290,162,292,156,
				296,153,306,153,310,154,310,162,314,166,318,161,324,161,327,168,324,174,326,173,
				332,178,334,175,339,172,342,172,346,174,349,179,348,182,353,176,362,178,372,187,
				373,196,393,194,400,194,398,186,402,181,410,176,418,176,421,180,421,176,427,174,
				429,169,430,162,437,160,447,161,448,169,457,169,460,162,460,158,462,152,469,148,
				476,148,473,143,470,136,470,129,477,120,481,115,486,114,492,112,502,110,508,112,
				512,116,518,121,520,128,516,138,520,138,522,143,523,148,526,145,532,141,538,141,
				542,147,545,145,552,145,556,149,557,142,558,138,567,138,574,138,578,139,580,134,
				578,131,580,123,583,120,589,118,596,121,596,120,599,110,602,106,612,101,623,100,
				634,100,639,106,639,233,0,249};


setfillstyle(SOLID_FILL, CYAN);
bar(2,2,638,220);

setfillstyle(SOLID_FILL, LIGHTCYAN);
setcolor(CYAN);
fillpoly(164, cloudA);

int roadA[52]={570,477,556,457,536,433,520,413,501,391,478,370,459,356,442,340,423,327,392,310,
			   372,299,348,289,329,282,306,273,279,266,250,259,223,255,203,254,188,253,176,252,
			   164,252,147,255,119,261,96,267,89,271,250,479};
	
	int grassA[52]={1,282,6,279,13,278,20,276,30,274,38,272,48,271,60,270,72,269,85,269,
					96,271,114,275,126,280,142,285,171,299,198,313,221,329,246,346,286,383,304,400,
					315,414,332,433,350,454,366,476,367,480,2,479};
	int grassB[52]={178,260,184,254,188,252,193,250,202,248,212,248,226,248,240,248,257,249,274,250,
					290,251,315,254,336,257,352,258,369,262,386,264,407,268,431,272,454,274,472,280,
					486,282,532,291,578,301,638,315,640,477,540,476};
	int grassC[28]={364,262,378,258,392,256,408,252,424,249,444,245,482,239,510,235,571,226,586,226,
					609,225,639,227,640,335,368,285};
	int grassD[48]={462,248,440,243,383,229,368,226,351,224,325,215,312,214,294,212,270,208,261,208,
					219,204,194,204,177,204,159,204,138,204,105,208,88,210,69,214,55,216,40,220,
					28,223,3,230,2,286,475,329};
	int grassE[32]={230,208,248,201,265,196,286,194,304,191,328,189,346,187,373,187,400,190,437,196,
					457,200,483,207,518,214,580,227,605,248,232,254};

setcolor(BLACK);					
setfillstyle(SOLID_FILL, GREEN);
fillpoly(16, grassE);
fillpoly(24, grassD);
fillpoly(14, grassC);
fillpoly(26, grassB);

int grassLineA[44]={1,290,10,287,22,283,34,279,41,279,62,274,81,274,104,279,135,289,150,295,
					171,304,190,314,201,321,226,337,240,347,254,362,277,384,301,410,314,428,332,452,
					350,477,2,479};



setfillstyle(SOLID_FILL, DARKGRAY);
fillpoly(26, roadA);

setfillstyle(SOLID_FILL, LIGHTGREEN);
fillpoly(26, grassA);

setfillstyle(SOLID_FILL, GREEN);
fillpoly(22,grassLineA);

int rLineA[8]={398,411,420,401,478,479,444,480};
int rLineB[8]={172,267,189,262,207,269,194,275};
int rLineC[8]={144,261,159,265,176,261,168,257};
setfillstyle(SOLID_FILL, YELLOW);
fillpoly(4, rLineA);
fillpoly(4, rLineB);
fillpoly(4, rLineC);


	//white box
setfillstyle(SOLID_FILL, WHITE);
fillpoly(4,box);
drawpoly(20, roundbox);	

//borders
setfillstyle(SOLID_FILL, RED);
bar(0,471,640,480);	  
bar(0,0,12,480);
bar(627,0,640,480);
bar(0,0,640,31);
fillpoly(4, logonum);
fillpoly(4, levelnum);	

settextstyle(2,0,4);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(15,455, "Press TAB for hints");
outtextxy(470,455, "Press ESC to go back home");
}//level four

/***************************************************LEVEL FIVE***************************************************************/

void level_five(){

int umbrella1[50]={183,247,184,245,184,239,181,232,180,223,177,217,174,211,169,203,164,198,155,193,
				   147,189,138,185,130,183,119,181,107,181,94,181,85,183,78,188,68,195,60,203,
				   53,211,49,219,45,229,42,239,41,247};	
int umbrella2[46]={104,182,102,185,96,191,92,196,88,203,86,209,82,217,82,223,82,234,82,241,
					82,247,150,248,151,241,150,230,150,230,150,223,148,217,145,210,142,201,136,194,
					127,187,124,185,117,181};
int umbrella3[44]={42,248,42,251,44,254,46,259,50,261,56,263,62,262,68,261,75,258,76,256,
				   80,252,82,249,80,247,150,249,152,253,156,257,158,260,163,262,170,261,175,260,
				   180,255,184,247};
int umbrella4[24]={80,248,83,254,88,258,93,261,100,264,110,265,119,266,127,264,136,259,147,252,
					152,248,152,245};

setfillstyle(SOLID_FILL,CYAN);
bar(0,1,639,413);

setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(1,346,640,404);
rectangle(1,346,640,404);

setfillstyle(SOLID_FILL, DARKGRAY);
bar(639,409,2,479);

setfillstyle(SOLID_FILL,WHITE);
bar(2,404,639,416);
rectangle(2,404,639,416);

setfillstyle(SOLID_FILL,GREEN);
bar(40,404,97,417);
rectangle(40,404,97,417);
bar(154,403,208,415);
rectangle(154,403,208,415);
bar(487,404,542,416);
rectangle(487,404,542,416);
bar(599,405,639,416);
rectangle(599,405,639,416);

int footA[8]={114,374,103,381,105,385,115,378};
int footB[8]={116,374,129,380,125,384,115,376};
setfillstyle(SOLID_FILL,BLACK);
bar(111,261,116,385);
fillpoly(4, footA);
fillpoly(4, footB);

setfillstyle(SOLID_FILL,LIGHTGREEN);
fillpoly(25, umbrella1);

setfillstyle(SOLID_FILL, LIGHTRED);
fillpoly(23, umbrella2);
fillpoly(22, umbrella3);

setfillstyle(SOLID_FILL,LIGHTGREEN);
fillpoly(12, umbrella4);

int table[46]={148,343,145,341,140,340,135,338,129,337,122,337,114,336,104,336,96,337,92,339,
				86,341,80,343,80,346,81,346,84,348,88,349,98,350,106,350,116,350,129,350,
				139,348,144,348,147,346};
setfillstyle(SOLID_FILL, WHITE);
fillpoly(23, table);

int roof[10]={240,172,268,63,595,64,626,169,624,175};
setfillstyle(SOLID_FILL, WHITE);
bar(252,172,606,381);
setfillstyle(SOLID_FILL,YELLOW);
bar(267,172,594,220);
rectangle(267,172,594,220);
setfillstyle(SOLID_FILL, LIGHTGREEN);
bar(265,311,597,380);
rectangle(265,311,597,380);
setfillstyle(SOLID_FILL, GREEN);
bar(252,172,271,381);
rectangle(252,172,271,381);
bar(587,172,606,381);
rectangle(587,172,606,381);
setfillstyle(SOLID_FILL, RED);
fillpoly(5, roof);

setfillstyle(SOLID_FILL, BLACK);
bar(551,270,554,281);

setfillstyle(SOLID_FILL, DARKGRAY);
bar(534,281,574,292);
rectangle(534,281,574,292);
bar(533,251,573,272);
rectangle(533,251,573,272);
bar(410,183,568,186);
bar(408,198,564,201);
setfillstyle(SOLID_FILL, LIGHTGRAY);
bar(530,292,578,311);
rectangle(530,292,578,311);

	//white box
setfillstyle(SOLID_FILL, WHITE);
fillpoly(4,box);
drawpoly(20, roundbox);	

//borders
setfillstyle(SOLID_FILL, RED);
bar(0,471,640,480);	  
bar(0,0,12,480);
bar(627,0,640,480);
bar(0,0,640,31);
fillpoly(4, logonum);
fillpoly(4, levelnum);		
settextstyle(2,0,4);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(15,455, "Press TAB for hints");
outtextxy(470,455, "Press ESC to go back home");
}//level_five


/*************************************************************LEVEL SIX**************************/
void level_six(){
	
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(0,1,639,476);
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(260,72,383,468);
	bar(45,71,266,467);
	rectangle(45,71,266,467);
	
	
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(57,84,254,423);
	bar(46,1,592,71);
	rectangle(46,1,592,71);
	bar(385,85,583,423);
	bar(267,84,374,478);
	
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(184,12,456,58);
	rectangle(187,16,453,54);
	bar(373,71,593,468);
	rectangle(373,71,593,468);

	
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(384,85,583,425);
	
	setfillstyle(SOLID_FILL, BLACK);
	bar(62,93,250,418);
	bar(270,91,367,464);
	bar(390,91,578,416);
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(61,395,252,417);
	bar(389,396,578,417);
	
	int mannA[82]={73,174,73,172,71,166,70,162,74,158,83,155,85,152,85,146,85,143,97,143,
				   97,151,99,154,106,158,111,160,110,172,104,216,94,312,93,402,97,403,99,403,
				   103,406,108,405,109,402,111,401,113,409,111,411,102,409,99,412,84,411,84,405,
				   75,409,73,411,67,409,68,402,73,402,77,405,82,404,83,401,89,401,89,317,
				   89,285};
	int mannB[68]={143,178,147,177,149,175,149,172,151,168,150,164,161,164,162,170,162,174,165,178,
				   170,178,159,301,158,400,164,402,167,402,173,402,175,399,177,404,178,408,175,411,
				   173,408,167,408,162,409,149,409,147,407,139,407,137,410,134,403,135,399,139,404,
				   145,404,149,402,153,402,154,270};
	int mannC[72]={470,178,473,176,477,175,479,173,479,170,479,166,489,165,489,170,489,174,490,176,
				   496,177,486,316,486,400,488,402,492,402,493,404,498,403,501,401,503,400,505,406,
				   505,410,500,407,491,408,477,409,475,406,470,406,467,410,464,412,461,407,463,403,
				   466,400,469,404,475,404,477,402,482,402,481,307};
	int mannD[74]={533,198,530,184,525,169,525,162,539,154,541,152,541,144,550,144,551,151,553,156,
				   564,160,565,165,562,190,555,213,549,293,549,403,555,403,557,406,562,404,564,402,
				   567,403,568,410,562,409,560,408,555,410,538,409,529,408,529,412,524,409,524,404,
				   526,403,529,403,531,405,537,405,538,402,543,402,546,253};
				   
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(41, mannA);
	fillpoly(34, mannB);
	fillpoly(36, mannC);
	fillpoly(37, mannD);

	int dressA1[58]={73,161,80,155,83,161,88,165,91,167,97,163,101,159,103,156,111,160,109,169,
					109,179,111,185,109,191,108,201,104,208,107,215,113,237,110,239,112,257,109,259,
					105,257,101,257,93,251,87,253,75,250,73,253,76,209,78,207,74,204};
	int dressA2[40]={74,247,72,293,75,293,75,305,79,305,83,308,86,308,87,313,91,316,94,318,
					 97,311,98,316,101,311,103,308,105,308,105,301,107,301,107,288,113,287,108,246};
					 
	int dressB[52]={133,185,143,179,146,184,150,186,154,188,159,188,166,184,169,178,177,186,180,191,
					177,199,171,219,169,235,175,249,175,256,175,271,173,295,170,301,159,299,155,297,
					151,299,139,299,137,250,142,239,143,236,143,228};
   	int dressC[90]={471,174,467,176,464,178,461,184,459,192,465,197,469,199,468,204,471,216,472,224,
	   				 469,236,467,252,463,268,459,282,457,296,453,306,461,310,461,313,474,314,477,316,
					 493,316,495,314,508,314,509,308,513,310,509,276,503,262,501,256,499,246,498,239,
					 497,229,497,216,502,204,503,198,506,194,506,188,504,184,501,180,495,177,494,175,
					 491,181,487,184,483,184,479,184,474,178};
	int dressD[74]= {529,178,530,176,531,170,532,165,532,160,530,156,532,155,534,164,534,172,544,180,
					 545,182,546,179,551,176,557,170,557,167,557,158,559,156,559,172,563,178,560,212,
					 560,216,565,231,567,240,574,258,578,286,571,288,571,292,556,292,556,297,537,296,
					 536,292,522,292,522,289,516,287,525,238,528,225,532,216};
					
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	fillpoly(20, dressA2);				
	setfillstyle(SOLID_FILL, CYAN);
	fillpoly(29, dressA1);
	setfillstyle(SOLID_FILL, LIGHTRED);
	fillpoly(26, dressB);
	setfillstyle(SOLID_FILL, GREEN);
	fillpoly(45, dressC);
	setfillstyle(SOLID_FILL, YELLOW);
	fillpoly(37, dressD);



	//white box
setfillstyle(SOLID_FILL, WHITE);
fillpoly(4,box);
drawpoly(20, roundbox);	

//borders
setfillstyle(SOLID_FILL, RED);
bar(0,471,640,480);	  
bar(0,0,12,480);
bar(627,0,640,480);
bar(0,0,640,31);
fillpoly(4, logonum);
fillpoly(4, levelnum);	
settextstyle(2,0,4);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(15,455, "Press TAB for hints");
outtextxy(470,455, "Press ESC to go back home");
}

/**************************************************************************LEVEL SEVEN***************************************/

void level_seven(){
	
	
	int topA[106]={1,0,0,79,5,85,7,88,16,92,27,94,37,94,48,92,57,88,65,80,
				64,4,129,2,128,80,133,86,139,90,151,94,159,94,171,94,181,90,191,82,
				191,2,256,2,256,13,256,79,259,84,267,91,275,93,288,94,302,92,312,89,
				319,82,319,78,319,2,385,3,384,80,389,86,395,90,405,93,417,93,430,93,
				441,88,449,79,447,2,513,2,512,80,516,86,525,90,537,92,551,94,563,91,
				571,86,576,81,575,0};
	int topB[110]={63,3,63,82,67,84,73,89,79,91,88,94,99,96,112,94,126,86,130,79,
				 131,3,190,3,190,74,190,78,195,85,205,92,219,94,227,94,242,92,249,88,
				 256,80,259,73,258,3,317,1,318,77,321,82,331,90,341,94,355,96,370,92,
				 377,89,386,82,389,74,387,2,444,3,445,75,448,82,455,88,467,94,481,94,
				 491,94,503,89,512,84,516,78,514,4,574,6,574,79,578,84,589,88,595,92,
				 609,94,620,94,631,90,639,83,639,3};

setfillstyle(SOLID_FILL, LIGHTCYAN);
bar(639,387,1,51);
setfillstyle(SOLID_FILL, DARKGRAY);
bar(1,387,639,479);
rectangle(1,387,639,479);
setfillstyle(SOLID_FILL, YELLOW);
fillpoly(55, topB);	
setfillstyle(SOLID_FILL, LIGHTGREEN);
fillpoly(53, topA);

setfillstyle(SOLID_FILL, BROWN);
bar(117,174,217,267);
rectangle(117,174,217,267);

setfillstyle(SOLID_FILL, CYAN);
bar(408,180,533,255);
rectangle(408,180,533,255);

setfillstyle(SOLID_FILL, MAGENTA);
bar(271,190,367,257);

int tableA[96]={157,333,160,337,162,341,162,345,159,349,162,353,162,360,160,364,157,371,153,379,
				151,386,151,395,153,403,158,411,157,415,155,417,145,415,139,415,127,415,120,417,
				112,419,107,419,104,417, 92,423,248,423,237,419,235,421,229,419,222,419,212,417,
				204,415,198,415,190,415,183,415,181,414,183,407,185,401,187,393,187,382,182,373,
				179,366,179,358,177,353,178,349,175,344,177,343,178,339,179,331};
int tableB[72]= {457,331,465,343,463,349,465,353,463,361,455,379,455,387,455,398,458,408,463,414,
				458,417,451,415,438,414,429,414,421,418,413,419,407,417,395,423,550,424,538,419,
				534,420,525,420,510,415,500,415,488,416,484,415,486,407,489,401,491,393,489,379,
				484,370,481,362,479,355,480,349,478,344,483,331};

setfillstyle(SOLID_FILL, BROWN);
bar(42,315,296,329);
rectangle(42,315,296,329);
bar(35,311,301,316);
rectangle(35,311,301,316);
bar(343,315,599,329);
rectangle(343,315,599,329);
bar(339,311,603,317);
rectangle(339,311,603,317);
fillpoly(48, tableA);
bar(70,324,265,335);
rectangle(70,324,265,335);
fillpoly(36,tableB);
bar(373,326,574,333);
rectangle(373,326,574,333);

setfillstyle(SOLID_FILL, GREEN);
bar(67,369,129,377);
rectangle(67,369,129,377);
bar(511,369,573,377);
rectangle(511,369,573,377);

setfillstyle(SOLID_FILL, LIGHTGREEN);
bar(66,361,129,370);
rectangle(66,361,129,370);
bar(511,361,574,371);
rectangle(511,361,574,371);

setfillstyle(SOLID_FILL, WHITE);
bar(125,179,213,261);
rectangle(125,179,213,261);
bar(414,185,525,253);
rectangle(414,185,525,253);
bar(65,310,131,317);
rectangle(65,310,131,317);
bar(65,325,131,332);
rectangle(65,325,131,332);
bar(67,339,130,347);
rectangle(67,339,130,347);
bar(57,294,71,425);
rectangle(57,294,71,425);
bar(123,295,139,427);
rectangle(123,295,139,427);
bar(512,310,573,317);
rectangle(512,310,573,317);
bar(513,323,570,332);
rectangle(513,323,570,332);
bar(513,339,574,348);
rectangle(513,339,574,348);
bar(501,294,515,426);
rectangle(501,294,515,426);
bar(567,294,583,426);
rectangle(567,294,583,426);

setfillstyle(SOLID_FILL, LIGHTGRAY);
bar(143,193,195,247);
bar(432,200,506,238);



		//white box
setfillstyle(SOLID_FILL, WHITE);
fillpoly(4,box);
drawpoly(20, roundbox);	


//borders
setfillstyle(SOLID_FILL, RED);
bar(0,471,640,480);	  
bar(0,0,12,480);
bar(627,0,640,480);
bar(0,0,640,31);
fillpoly(4, logonum);
fillpoly(4, levelnum);

settextstyle(2,0,4);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(15,455, "Press TAB for hints");
outtextxy(470,455, "Press ESC to go back home");
}

/*****************************************************************************LEVEL EIGHT**************************************/

void level_eight(){
	

setfillstyle(SOLID_FILL, CYAN);
bar(3,1,639,363);
setfillstyle(SOLID_FILL, BROWN);
bar(1,363,639,479);
rectangle(1,363,639,479);

int curve1[50]={1,328,15,314,32,305,49,292,64,284,86,269,198,219,219,213,249,208,275,206,
				303,205,324,204,343,204,371,206,398,209,417,212,451,220,474,226,504,239,533,252,
				557,268,624,316,639,330,639,364,1,365};
int curve2[40]={9,362,61,304,106,276,166,254,203,242,228,237,251,232,269,230,298,229,317,229,
			 339,228,371,230,408,234,428,238,456,244,483,254,501,259,522,268,581,304,639,363};
setfillstyle(SOLID_FILL, DARKGRAY);
fillpoly(25, curve1);

setfillstyle(SOLID_FILL, LIGHTGRAY);
fillpoly(20, curve2);

int towerA[10]={58,365,85,328,85,182,195,183,199,364};	
int towerB[12]={69,101,69,133,87,177,197,177,215,134,213,102};
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillpoly(6, towerB);
setfillstyle(SOLID_FILL, DARKGRAY);
fillpoly(5, towerA);
bar(77,174,208,185);
rectangle(77,174,208,185);
bar(81,79,198,99);
rectangle(81,79,198,99);
bar(59,96,225,104);
rectangle(59,96,225,104);
bar(68,133,213,136);
bar(88,105,91,174);
bar(121,105,125,174);
bar(157,105,160,174);
bar(61,304,585,308);
bar(233,235,239,348);
bar(322,228,327,338);
bar(413,235,417,336);
bar(501,260,507,336);

int apA[68]={181,394,163,392,146,392,135,393,127,390,111,390,98,389,83,386,75,384,67,380,
			  66,372, 70,369, 79,364, 91,358,105,348,119,341,134,336,155,333,183,329,505,
			 324,564,255,591,255,592,254,558,332,591,369,570,368,545,352,508,374,500,379,
			 489,382,477,386,455,390,416,392,251,394};
int apB[16]={106,348,150,348,153,348,157,352,157,355,155,358,149,361,86,360};
int apC[8]={177,405,166,405,159,391,169,388};
	
setfillstyle(SOLID_FILL, LIGHTBLUE);
fillpoly(4, apC);
fillpoly(34, apA);	

setfillstyle(SOLID_FILL, BLUE);
fillpoly(8, apB);
bar(169,405,175,419);
rectangle(169,405,175,419);

setcolor(WHITE);
setfillstyle(SOLID_FILL, WHITE);
circle(500,354,7);
floodfill(500,354, WHITE);
circle(471,355,7);
floodfill(471, 355, WHITE);

setcolor(LIGHTBLUE);
setfillstyle(SOLID_FILL, LIGHTBLUE);
circle(172,429,12);
floodfill(172,429, LIGHTBLUE);
circle(425,429,12);
floodfill(425, 429, LIGHTBLUE);

setcolor(BLUE);
setfillstyle(SOLID_FILL, BLUE);

circle(172,429,8);
floodfill(172,429, BLUE);

setcolor(BLACK);
int door[22]={187,388,187,360,188,354,192,348,198,344,201,342,230,342,235,344,239,350,242,356,242,388};
setfillstyle(SOLID_FILL, BLUE);
bar(185,395,245,402);
bar(186,409,243,460);
fillpoly(11, door);
setfillstyle(SOLID_FILL, LIGHTBLUE);
bar(186,387,244,394);
rectangle(186,387,244,394);
bar(185,402,246,410);
rectangle(185,402,246,410);
bar(187,416,243,423);
rectangle(187,416,243,423);
bar(187,431,245,438);
rectangle(187,431,245,438);
bar(188,446,244,452);
rectangle(188,446,244,452);

setfillstyle(SOLID_FILL, LIGHTGRAY);
bar(182,361,187,460);
rectangle(182,361,187,460);
bar(243,362,249,460);
rectangle(243,362,249,460);

//white box
setfillstyle(SOLID_FILL, WHITE);
fillpoly(4,box);
drawpoly(20, roundbox);	
//borders
setfillstyle(SOLID_FILL, RED);
bar(0,471,640,480);	  
bar(0,0,12,480);
bar(627,0,640,480);
bar(0,0,640,31);
fillpoly(4, logonum);
fillpoly(4, levelnum);

settextstyle(2,0,4);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(15,455, "Press TAB for hints");
outtextxy(470,455, "Press ESC to go back home");
}

/*********************************LOGO TWO****************************************************************/
logo_two()
{
int slideStand[88]={251,300,250,303,245,304,242,305,240,303,238,299,238,296,238,294,259,163,259,159,
					261,156,265,155,266,154,270,155,386,159,389,160,392,162,394,166,394,171,426,297,
					424,303,422,306,417,307,414,304,413,303,399,253,379,256,371,304,369,308,366,309,
					361,309,358,305,357,304,358,302,376,175,278,173,306,296,306,301,301,303,295,299,
					294,297,283,253,282,252,259,258};
int seatA[22]={324,274,267,272,263,273,260,277,259,281,259,289,261,292,317,296,329,284,328,280,327,275};
int lineA[36]={312,157,310,157,309,159,307,161,307,166,306,169,308,172,272,273,265,273,301,173,
			   301,169,299,165,299,161,301,157,304,153,307,153,313,153,315,157};
int lineB[34]={367,159,362,159,361,160,360,164,359,169,361,175,324,277,317,274,354,175,353,172,
			   351,169,351,164,352,159,356,155,359,153,363,153,368,157};
int tri1[6]={387,180,378,245,400,239};
int tri2[6]={267,173,259,245,282,238};
setcolor(BLACK);

setfillstyle(SOLID_FILL, LIGHTMAGENTA);
fillpoly(44, slideStand);

setfillstyle(SOLID_FILL, WHITE);
fillpoly(3, tri1);
fillpoly(3, tri2);

setfillstyle(SOLID_FILL, BROWN);
fillpoly(18, lineA);
fillpoly(17, lineB);

setfillstyle(SOLID_FILL, LIGHTGREEN);
fillpoly(11, seatA);


//borders
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "2");
settextstyle(2,0,10);
outtextxy(270,8," of 2");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);	
	
}//logo_two


/********************************************************LOGO THREE*****************************/
void logo_three()
{
	
setcolor(BLACK);

int ss1[8]={214,292,415,186,443,189,243,298};
int ss2[10]={343,243,364,270,335,285,305,274,313,256};
int handle1[26]={264,259,263,281,262,283,260,283,258,283,258,257,245,252,242,250,242,247,245,247,
				 280,259,281,261,280,265};
int handle2[30]={407,203,405,205,405,207,401,205,400,183,388,180,385,179,387,177,386,175,389,174,
				 425,179,426,181,425,184,423,184,407,184};
				 
setfillstyle(SOLID_FILL, MAGENTA);
fillpoly(5, ss2);

setfillstyle(SOLID_FILL, YELLOW);
fillpoly(4, ss1);

setfillstyle(SOLID_FILL, BLUE);
fillpoly(13, handle1);
fillpoly(15, handle2);
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "2");


settextstyle(2,0,10);
outtextxy(270,8," of 2");	
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);

} //logo_three

/*************************************************************************LOGO FOUR*********************************/
void logo_four(){

setcolor(BLACK);	
int stape1[48]={271,245,243,235,245,204,360,194,370,194,381,194,399,196,409,200,419,206,426,215,
				431,228,434,241,435,250,432,255,268,316,228,291,233,275,266,296,384,255,360,244,
				367,241,381,249,383,248,382,224};
int stape2[10]={253,239,250,254,277,268,384,236,381,225};
int stape3[8]={235,277,266,295,384,256,355,240};
int stape4[8]={254,277,271,289,297,279,279,268};
int stape5[4]={274,245,277,266};
int stape6[14]={247,205,272,213,375,203,384,201,395,200,409,200,420,205};
int stape7[4]={271,213,272,243};				
setfillstyle(SOLID_FILL, BLACK);
bar(398,255,346,217);


setfillstyle(SOLID_FILL, LIGHTGRAY);
fillpoly(4, stape3);
fillpoly(5, stape2);	
fillpoly(4, stape4);
drawpoly(2, stape5);
			
				
setfillstyle(SOLID_FILL, RED);
fillpoly(24, stape1);
drawpoly(7, stape6);
drawpoly(2, stape7);
	//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);


//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "3");
settextstyle(2,0,10);
outtextxy(270,8," of 3");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);	
}
/******************************************************************LOGO FIVE****************************************/
void logo_5(){
setcolor(BLACK);
int prot1[54]={235,289,235,282,235,274,237,265,240,257,245,245,251,239,256,231,263,225,269,219,
			   278,213,283,209,296,203,309,199,319,196,332,196,341,196,351,199,362,203,373,208,
			   383,214,393,222,401,231,409,243,414,255,420,271,421,290};
int prot2[60]={311,267,313,259,317,256,322,253,327,252,333,252,339,255,344,257,347,265,347,269,
			   388,267,387,261,383,255,379,249,375,243,369,237,361,233,356,229,347,225,337,223,
			   328,223,320,223,313,224,307,227,299,229,293,232,281,240,274,247,270,257,268,267};	
setfillstyle(SOLID_FILL,YELLOW);
fillpoly(27, prot1);
setfillstyle(SOLID_FILL, WHITE);
fillpoly(30, prot2);	
circle(329,268,5);
floodfill(329, 268, BLACK);
setfillstyle(SOLID_FILL, BLACK);
bar(327,198,328,213);
int line1[6]={341,198,339,205,338,216};
int line2[6]={352,200,350,208,348,214};
int line3[6]={364,206,361,211,359,219};
int line4[6]={375,211,371,216,367,224};
int line5[6]={385,218,380,223,373,230};
int line6[6]={394,228,387,232,379,238};
int line7[6]={403,238,396,242,387,246};
int line8[6]={411,249,401,252,391,256};
int line9[6]={413,260,405,263,394,263};
int line10[6]={314,199,315,206,316,216};
int line11[6]={295,206,299,211,300,218};
int line12[6]={287,210,290,216,294,223};
int line13[6]={276,217,280,221,285,228};
int line14[6]={269,225,272,229,275,236};
int line15[6]={259,232,263,236,269,242};
int line16[6]={250,242,257,245,262,248};
int line17[6]={245,252,253,256,259,258};
int line18[6]={241,263,250,265,258,267};

drawpoly(3, line1);
drawpoly(3, line2);
drawpoly(3, line3);
drawpoly(3, line4);
drawpoly(3, line5);
drawpoly(3, line6);
drawpoly(3, line7);
drawpoly(3, line8);
drawpoly(3, line9);
drawpoly(3, line10);
drawpoly(3, line11);
drawpoly(3, line12);
drawpoly(3, line13);
drawpoly(3, line14);
drawpoly(3, line15);
drawpoly(3, line16);
drawpoly(3, line17);
drawpoly(3, line18);



		//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "3");
settextstyle(2,0,10);
outtextxy(270,8," of 3");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);	

}

/***********************************************************************LOGO SIX************************************/
void logo_6 (){
	
int marker1[8]={279,271,313,289,375,177,343,158};
int marker2[8]={281,271,287,258,319,276,313,290};
int marker3[8]={343,157,376,177,369,190,334,173};
int marker4[8]={348,159,361,132,389,148,370,174};
int marker5[8]={373,129,385,136,381,143,367,138};
int mline1[6]={367,137,360,151,352,163};
int mline2[6]={374,140,368,151,361,165};
int mline3[6]={382,145,374,159,367,169};
int marker6[12]={282,273,284,291,279,297,291,304,293,297,309,289};
int marker7[8]={281,297,274,309,285,310,291,299};

setcolor(BLACK);
setfillstyle(SOLID_FILL, DARKGRAY);
fillpoly(4, marker1);
fillpoly(4, marker5);
fillpoly(4, marker4);
drawpoly(3, mline1);
drawpoly(3, mline2);
drawpoly(3, mline3);
fillpoly(4, marker7);
setfillstyle(SOLID_FILL, WHITE);	
fillpoly(4, marker2);
fillpoly(4, marker3);
fillpoly(6, marker6);



//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "3");
settextstyle(2,0,10);
outtextxy(270,8," of 3");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
	
}

/*******************************************************************LOGO 7*******************************************/

void logo_7(){
	int part1[76]={271,174,282,186,285,182,287,178,290,175,293,172,297,168,
302,166,307,164,314,163,318,163,330,163,333,163,338,164,345,165,349,166,
354,169,358,171,362,175,365,179,368,185,380,173,376,168,371,163,368,161,
362,157,358,154,354,153,348,151,342,149,337,148,314,148,308,150,302,150,
297,152,289,156,283,159,277,166};

int part2[136]={270,175,267,180,265,187,263,193,261,200,260,211,259,232,
260,240,262,248,264,257,268,266,273,275,279,282,285,287,291,291,299,294,
307,296,317,297,334,297,340,297,346,295,352,294,359,291,366,287,372,282,
377,277,382,270,385,262,388,253,390,243,391,232,392,216,391,209,390,201,
389,193,386,184,381,175,379,193,381,199,382,205,383,214,383,224,382,237,
381,245,380,251,377,259,373,266,367,273,361,279,352,283,343,287,335,288,
325,289,314,288,306,287,297,283,289,278,283,273,278,267,273,257,270,250,
266,245,263,237,261,230,261,221,261,214,262,204,263,196,};

int part3[116]={271,197,276,212,275,221,275,228,276,236,277,244,279,250,
282,257,285,265,290,271,296,276,301,279,310,282,319,284,329,284,338,283,
346,281,353,278,359,273,365,267,368,260,372,251,374,243,375,234,375,225,
376,217,375,208,378,198,380,204,381,211,382,220,381,229,380,238,378,244,
376,251,370,259,368,263,363,271,358,276,350,280,344,283,338,284,333,285,
325,285,317,284,309,283,302,280,297,277,291,274,288,270,283,264,279,260,
276,257,273,252,270,244,269,236,268,229,268,216};


int part4[82]={274,197,277,209,286,214,294,217,300,220,305,223,311,228,
315,233,320,240,324,247,325,254,328,247,330,241,333,236,337,231,341,227,
346,223,351,219,357,216,365,212,373,209,377,196,369,201,361,206,354,210,
348,213,342,218,337,224,333,230,330,236,327,243,326,247,323,241,321,237,
318,231,315,226,312,223,306,217,299,213,290,208,282,203};

int part5[82]={270,176,271,191,277,196,281,200,288,204,293,207,300,210,
305,214,311,219,317,225,322,233,325,242,329,233,332,227,336,223,340,218,
346,212,353,208,360,204,369,199,374,195,378,191,379,175,374,181,369,185,
362,190,356,194,349,199,342,203,337,208,332,215,328,223,325,230,322,222,
319,217,316,212,312,208,306,203,299,199,291,194,281,188};

int part6[64]={272,174,277,178,282,172,287,168,291,164,297,161,302,158,
310,156,316,155,334,155,339,156,347,158,353,160,359,163,365,168,371,173,
373,176,378,172,374,168,369,163,364,159,357,156,351,154,344,152,336,150,
318,150,311,151,302,153,294,155,288,159,282,163,277,169};


setbkcolor(15);

setcolor(8);
setfillstyle(1,8);
fillpoly(38,part1);
fillpoly(68,part2);
fillpoly(58,part3);
fillpoly(41,part4);
fillpoly(41,part5);

setcolor(8);
setfillstyle(1,15);
fillpoly(32,part6);

				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "4");
settextstyle(2,0,10);
outtextxy(270,8," of 4");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}

/********************************************************************LOGO 8*****************************************/

void logo_8(){
	int n1[54]={299,189,293,196,287,206,282,216,275,230,269,244,265,253,261,265,
260,267,258,267,253,263,246,256,243,252,240,245,238,241,237,236,238,230,
239,226,242,220,244,216,251,209,257,204,267,198,275,194,286,191,293,188,
298,188};

int n2[60]={327,184,324,186,321,188,319,191,317,195,313,203,310,213,310,217,
310,220,312,223,314,225,317,226,322,227,326,227,331,226,338,223,348,219,
356,215,367,210,375,205,380,201,384,198,386,196,387,194,386,193,385,191,
376,189,361,186,350,184,340,184};

int n3[64]={280,274,279,275,278,277,279,278,281,279,285,280,297,283,307,285,
324,286,330,287,334,287,337,286,340,285,342,284,346,280,349,273,351,268,
353,260,354,253,354,251,353,248,352,247,351,245,347,244,345,244,341,244,
337,245,330,246,319,251,311,254,301,260,294,263};

int n4[54]={406,203,405,204,403,206,393,232,389,242,384,252,378,263,373,272,
366,280,366,282,367,283,369,283,375,281,389,277,397,273,406,267,414,261,
418,258,421,253,424,249,426,244,427,239,427,234,426,227,424,222,420,216,
414,210};

setbkcolor(15);

setcolor(8);
setfillstyle(1,8);
fillellipse(333,235,105,60);

setcolor(15);
setfillstyle(1,15);
fillpoly(27,n1);
fillpoly(30,n2);
fillpoly(32,n3);
fillpoly(27,n4);

				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "4");
settextstyle(2,0,10);
outtextxy(270,8," of 4");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);

}

/********************************************************************LOGO 9*****************************************/

void logo_9(){
	

int par1[10]={325,153,355,200,325,250,295,200,325,153};
int par2[10]={325,250,385,250,413,295,355,295,325,250};
int par3[10]={325,250,297,295,237,295,265,250,325,250};


setbkcolor(15);
setcolor(4);
setfillstyle(SOLID_FILL,RED);
fillpoly(5,par1);
fillpoly(5,par2);
fillpoly(5,par3);
				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "4");
settextstyle(2,0,10);
outtextxy(270,8," of 4");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);

}

/***********************************************************************LOGO 10**********************************/

void logo_10(){
	int h[98]={295,289,298,279,299,273,301,266,303,262,304,259,305,257,307,255,310,254,
311,253,313,253,315,252,325,252,330,252,333,252,337,253,340,254,342,255,344,257,
347,263,351,273,353,280,355,290,376,288,385,152,370,151,369,157,368,162,366,171,
362,188,358,206,355,217,353,225,351,230,348,233,345,236,338,238,331,240,318,240,
312,239,306,237,304,235,301,231,298,227,294,215,280,152,265,153,274,288,295,289};

int sqr1[96]={322,145,351,145,361,145,372,146,382,148,390,149,396,151,
401,154,405,157,409,161,411,166,413,176,414,200,414,221,414,232,412,245,
411,255,407,267,403,278,399,282,395,286,388,289,366,293,327,294,298,294,
289,294,282,293,273,292,263,290,259,287,254,285,249,280,245,274,241,265,
239,256,239,248,235,198,235,189,236,180,237,171,238,168,242,163,245,158,
249,155,254,152,261,149,284,147,322,145};

int sqr2[102]={263,141,284,139,303,138,325,137,339,137,354,138,368,139,
385,141,394,142,400,144,406,147,412,150,416,155,419,159,422,165,424,171,
425,183,424,221,422,240,420,256,417,269,415,275,412,280,409,285,404,289,
397,293,389,296,374,298,312,300,290,299,279,299,270,297,262,296,255,294,
250,292,245,289,241,286,239,282,235,275,231,264,229,253,227,238,225,195,
225,181,226,174,228,166,231,160,234,155,239,150,244,147,253,144};

setbkcolor(15);

setcolor(8);
setfillstyle(1,8);
fillpoly(49,sqr2);

setcolor(15);
setfillstyle(1,15);
fillpoly(48,sqr1);

setcolor(8);
setfillstyle(1,8);
fillpoly(48,h);


				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "4");
settextstyle(2,0,10);
outtextxy(270,8," of 4");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}

/*****************************************************************LOGO 11****************************************/

void logo_11(){
	int leaf1[124]={235,228,230,229,227,232,225,235,224,237,226,239,228,239,
229,241,230,244,231,246,232,249,234,251,237,252,241,253,244,252,247,251,
248,251,249,251,249,253,251,255,253,257,256,258,259,260,262,261,266,262,
268,261,271,260,274,258,277,257,280,257,283,257,285,258,287,259,289,259,
292,259,294,257,297,255,299,252,302,250,304,249,306,249,309,248,312,249,
314,248,316,247,318,245,319,243,321,241,323,240,326,240,324,237,324,237,
316,239,310,241,302,242,293,244,284,243,275,244,265,242,258,241,250,238,
242,235};

int leaf2[138]={330,232,328,235,329,238,331,240,334,241,336,241,337,243,
339,245,340,247,342,248,344,248,347,248,349,248,351,248,353,248,355,250,
356,251,358,253,360,255,362,257,365,259,367,259,369,259,371,258,372,257,
374,256,377,257,379,257,381,258,384,259,386,260,388,260,392,260,396,260,
400,259,401,258,404,256,406,254,407,251,410,252,412,252,415,253,418,252,
420,251,422,250,423,248,424,246,424,244,425,242,427,240,429,239,431,238,
431,236,430,234,428,231,426,230,424,229,417,234,412,236,408,238,401,240,
396,241,388,242,380,243,370,243,360,242,352,241,342,238};

int cheese[150]={252,262,256,264,260,265,263,264,268,264,271,262,275,261,
278,260,281,260,284,261,286,262,289,262,293,262,295,261,297,259,300,257,
303,254,305,253,305,252,307,251,309,251,311,251,314,251,316,250,319,249,
321,247,322,245,324,244,326,243,328,241,330,243,333,245,334,246,335,248,
338,250,340,252,343,252,345,252,348,252,350,252,351,253,353,254,354,255,
356,258,358,259,360,261,363,263,366,263,369,262,372,261,376,260,377,260,
381,262,384,263,388,264,391,264,394,265,399,263,404,261,403,276,395,273,
385,270,375,269,361,268,346,267,329,266,320,267,306,268,291,269,277,270,
261,272,252,273,247,275,248,269,249,266};

int burger[40]={247,260,242,260,238,261,236,262,235,264,235,267,235,269,
237,272,238,273,241,274,244,274,419,274,421,274,424,272,425,271,425,267,
425,264,424,263,423,262,420,260};

int bun2[22]={240,278,239,295,241,297,242,299,244,299,247,299,415,299,
417,297,419,296,419,294,418,278};

int seed1[26]={255,210,255,208,255,206,256,206,258,206,259,206,260,208,
262,210,263,213,264,216,265,219,263,221,260,220};
int seed2[24]={292,209,293,208,294,205,296,203,298,203,300,204,300,208,
300,210,298,215,295,218,292,218,291,215};
int seed3[26]={322,201,322,205,323,208,325,210,327,212,329,214,331,214,
332,213,333,210,331,207,329,203,326,200,323,200};
int seed4[26]={306,174,306,177,307,181,309,183,311,186,313,188,314,188,
316,187,316,184,315,180,313,177,312,175,309,174};
int seed5[22]={337,180,340,177,342,173,345,173,346,174,347,176,346,180,
344,184,341,187,338,187,336,184};
int seed6[22]={347,207,351,203,353,202,357,200,358,200,359,201,360,204,
357,208,353,211,349,212,347,210};
int seed7[24]={368,198,368,203,371,206,373,209,375,211,377,211,378,209,
377,205,376,201,375,199,374,197,371,196};
int seed8[24]={397,207,397,209,401,215,403,217,406,218,407,217,407,214,
407,211,404,206,402,205,399,203,397,206};
int seed9[22]={278,187,282,186,287,186,289,187,292,188,292,190,290,192,
285,194,282,194,276,193,275,190};
int seed10[20]={380,183,384,182,390,183,390,185,391,187,387,190,382,190,
377,189,376,186,378,184};

int back[168]={245,302,415,302,418,302,420,300,421,298,422,297,423,295,
423,278,424,277,426,275,428,272,429,270,429,265,429,263,428,261,426,259,
424,257,420,256,424,254,426,252,428,248,429,245,430,243,432,241,434,240,
435,237,435,235,434,232,432,229,429,227,425,225,429,223,429,221,430,218,
430,215,430,212,429,209,426,203,423,199,421,196,418,192,413,187,407,182,
400,177,392,172,382,167,373,164,364,161,355,159,345,158,332,157,323,157,
313,158,300,161,285,165,276,169,265,175,254,183,245,193,239,201,235,208,
232,217,232,221,232,224,228,226,223,229,221,234,220,237,221,239,224,241,
226,242,227,244,229,250,231,253,234,255,238,256,234,260,232,262,232,270,
233,273,236,275,236,300,237,300,241,302};


setbkcolor(15);
setlinestyle(0,4,3);

setcolor(8);
setfillstyle(1,8);
fillpoly(84,back);

setcolor(6);
setfillstyle(1,6);
fillpoly(20,burger);

setcolor(8);
setfillstyle(1,14);
fillpoly(75,cheese);

setcolor(10);
setfillstyle(1,10);
fillpoly(62,leaf1);
fillpoly(68,leaf2);

setcolor(14);
setfillstyle(1,14);
fillpoly(11,bun2);
sector(331,223,0,180,95,60);

setcolor(4);
setfillstyle(1,4);
sector(285,228,180,360,40,10);
sector(375,228,180,360,40,10);

setcolor(15);
setfillstyle(1,15);
fillpoly(13,seed1);
fillpoly(12,seed2);
fillpoly(13,seed3);
fillpoly(13,seed4);
fillpoly(11,seed5);
fillpoly(11,seed6);
fillpoly(12,seed7);
fillpoly(12,seed8);
fillpoly(11,seed9);
fillpoly(10,seed10);



				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "5");
settextstyle(2,0,10);
outtextxy(270,8," of 5");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}

/****************************************************************************LOGO 12******************************/

void logo_12(){
	int taco[274]={243,236,237,244,229,256,228,259,227,260,225,263,224,267,224,270,
222,273,221,276,220,281,221,285,222,290,224,294,227,298,230,298,234,299,
239,299,249,299,256,299,261,298,264,297,268,297,275,297,282,297,286,296,
289,296,294,296,303,295,308,294,314,295,321,295,326,295,338,293,342,292,
349,291,356,290,361,290,367,290,376,290,383,289,389,288,396,288,401,288,
409,288,414,287,416,286,418,285,422,284,427,283,429,282,431,281,432,279,
432,276,432,273,432,269,431,266,430,262,429,256,428,253,428,249,427,246,
425,242,422,236,420,231,419,228,419,225,416,222,414,220,413,218,409,216,
406,213,403,210,402,208,400,206,399,205,395,203,391,203,387,200,383,199,
379,196,372,195,364,195,360,194,353,194,347,193,336,195,329,196,321,199,
316,199,308,204,301,209,297,213,294,216,290,219,287,224,283,230,281,235,
277,240,272,248,269,252,266,258,264,264,262,269,260,274,257,276,254,280,
253,284,250,288,246,292,242,295,239,295,236,295,235,296,233,294,230,294,
228,293,226,292,226,289,227,288,228,286,232,284,231,281,229,282,227,283,
225,284,224,281,226,275,230,267,233,264,236,258,240,255,242,254,244,252,
242,247,244,245,243,241};

int gulay1[204]={269,254,271,250,273,247,276,244,279,238,282,235,285,230,288,225,
290,221,298,212,300,211,310,204,317,201,325,198,333,194,339,195,345,195,
351,195,354,194,362,196,371,196,378,198,385,200,388,201,393,203,395,204,
396,205,396,203,396,201,395,200,394,200,392,200,391,200,389,198,387,196,
383,193,382,192,379,191,377,190,376,187,373,187,369,188,368,187,367,186,
362,185,361,184,360,182,359,181,355,182,350,182,347,183,345,182,342,181,
340,180,338,180,336,182,333,182,333,181,332,180,329,180,326,180,324,180,
322,180,320,181,317,183,315,183,314,183,313,182,310,183,307,186,305,186,
301,187,299,188,296,190,292,193,289,195,286,196,283,196,280,196,278,198,
276,200,274,201,271,201,268,202,266,204,264,207,262,209,260,212,255,215,
252,218,250,221,249,225,247,226,246,228,244,231,244,234,243,238,244,241,
245,245,244,248,244,251,246,254};

int gulay2[68]={268,254,263,253,257,253,253,254,248,254,246,254,241,256,238,256,
236,259,237,260,238,262,236,264,236,266,234,267,232,269,228,274,228,276,
228,277,230,278,228,279,228,281,229,282,230,282,232,283,248,273,246,276,
247,279,248,279,253,276,256,270,259,268,260,269,262,269,266,262};

int beef[82]={249,272,246,273,244,274,242,275,240,276,238,276,237,278,236,280,
233,282,231,284,228,286,227,287,226,289,226,290,227,293,229,295,231,
294,233,294,235,296,237,296,238,295,240,296,242,295,245,293,249,289,
251,286,254,282,256,279,257,278,258,276,260,273,261,270,261,269,259,
269,256,271,255,273,254,274,251,275,250,278,248,279,246,278};

int tomato1[44]={263,253,260,250,258,247,258,244,258,242,258,241,260,239,262,236,
265,235,266,234,267,233,268,232,271,231,273,231,275,230,276,232,278,234,
279,236,280,238,274,246,272,249,270,253};

int tomato2[28]={290,219,289,217,289,213,289,211,290,210,290,208,291,206,294,205,
298,204,299,203,303,203,305,202,307,205,294,217};

int tomato3[22]={323,198,322,195,323,194,323,192,327,190,329,189,332,189,337,190,
341,191,342,191,343,194};

setbkcolor(15);

setcolor(8);
setfillstyle(1,10);
fillpoly(102,gulay1);

setcolor(4);
setfillstyle(1,4);
fillpoly(22,tomato1);
fillpoly(14,tomato2);
fillpoly(11,tomato3);

setcolor(8);
setfillstyle(1,6);
fillpoly(41,beef);

setcolor(8);
setfillstyle(1,14);
fillpoly(34,gulay2);
fillpoly(137,taco);


				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "5");
settextstyle(2,0,10);
outtextxy(270,8," of 5");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}


/********************************************************************************LOGO 15***************************/
void logo_13(){
	int c[130]={272,205,276,199,281,193,287,188,292,182,298,178,303,175,307,172,312,170,
314,170,316,171,317,173,318,175,317,178,315,181,313,184,308,186,302,191,
296,197,291,202,285,209,281,217,279,222,278,228,279,233,279,239,281,243,
283,247,285,252,289,255,292,258,295,260,298,261,301,261,306,260,310,259,
315,257,319,253,322,250,324,247,325,245,328,244,331,245,335,247,334,251,
331,254,329,260,324,268,318,273,313,277,306,279,300,280,295,281,289,279,
281,275,274,270,270,265,267,259,264,253,263,247,262,241,263,233,264,226,
265,219,267,213};

int k[98]={342,171,349,166,355,161,359,160,362,161,361,163,359,176,357,185,354,202,
352,213,352,222,352,248,356,245,361,241,364,238,366,234,368,230,369,227,
369,225,366,223,369,221,373,218,376,215,380,214,383,214,386,216,386,218,
386,221,385,225,381,230,377,236,368,247,382,260,386,262,390,265,394,268,
397,269,385,283,352,256,352,274,352,276,351,278,345,283,343,283,341,282,
340,280,338,254,337,235,338,205};



setbkcolor(15);

setcolor(4);
setfillstyle(1,4);
fillellipse(330,225,80,80);

setcolor(15);
setfillstyle(1,15);
fillpoly(65,c);
fillpoly(49,k);


				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "5");
settextstyle(2,0,10);
outtextxy(270,8," of 5");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}

/******************************************************************************LOGO 14****************************/

void logo_14()
{

int sqr1[10]={295,200,345,250,295,300,245,250,295,200};
int sqr2[10]={300,195,350,145,400,195,350,245,300,195};

setbkcolor(15);

setcolor(9);
setfillstyle(1,9);
fillpoly(5,sqr1);

setcolor(4);
setfillstyle(1,4);
fillpoly(5,sqr2);

setcolor(15);
setfillstyle(1,15);
circle(275,250,12);
floodfill(275,250,15);
circle(315,250,12);
floodfill(315,250,15);
circle(350,195,12);
floodfill(350,195,15);

				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "5");
settextstyle(2,0,10);
outtextxy(270,8," of 5");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}

/********************************************************************************LOGO 15****************************/
void logo_15(){
	int sqr1[32]={250,204,250,293,250,295,251,298,253,301,256,304,259,306,
261,307,264,308,268,309,316,309,313,306,278,245,274,245,270,243,266,240};

int sqr2[50]={394,179,394,294,393,299,391,303,387,306,383,308,380,309,
367,309,373,306,376,303,380,299,383,294,385,289,385,284,363,215,366,211,
368,208,367,205,366,202,349,167,378,167,382,168,385,170,389,172,392,175};

int small[20]={250,177,252,179,254,181,257,182,260,183,263,183,257,187,
255,189,253,191,250,194};

int cup[74]={317,303,281,240,276,240,273,239,271,237,255,201,255,198,256,196,
262,190,271,185,282,179,293,175,302,172,313,169,322,167,329,166,335,165,340,166,
344,167,345,170,361,205,362,207,357,214,379,281,379,286,379,290,377,294,375,297,
372,300,367,303,363,306,358,308,351,310,344,311,338,312,332,312,326,310};

int cup0[52]={259,201,269,201,274,197,280,195,287,191,293,188,300,186,306,184,
313,182,319,180,325,179,330,178,334,177,336,177,342,171,335,170,329,171,323,172,
315,173,308,175,299,178,290,181,282,184,274,188,267,192,262,196};

int cup1[48]={262,206,274,205,280,205,287,203,295,201,302,199,309,197,317,193,
323,190,330,187,337,183,343,178,357,206,352,211,347,215,339,219,330,224,323,227,
314,230,305,232,298,234,290,235,282,236,276,235};

int cup2[48]={286,240,293,239,302,238,309,236,317,234,323,231,330,229,337,225,
344,222,350,219,352,217,375,281,375,284,375,287,373,291,370,296,365,299,358,302,
352,304,345,305,340,306,332,306,328,305,324,303};

int swirl1[106]={280,171,281,167,281,163,280,159,277,155,271,153,267,153,263,154,
258,157,256,160,255,163,255,166,256,169,259,172,264,173,268,173,272,170,271,166,
268,163,266,164,263,164,262,162,264,160,267,159,271,159,274,161,276,164,277,169,
276,173,273,175,269,177,265,178,262,178,258,176,254,174,251,170,250,166,250,162,
251,158,254,155,258,151,262,149,267,148,272,149,277,150,281,153,284,156,286,160,
287,165,287,168,286,171,284,173,281,174};

int swirl2[124]={296,168,296,164,296,161,294,158,292,155,289,152,287,149,283,145,
283,142,282,139,283,135,285,131,287,128,290,126,293,124,298,122,303,121,307,121,
311,122,315,125,318,127,320,130,320,134,320,139,318,144,315,146,311,147,306,148,
302,147,300,145,298,139,300,135,305,133,309,134,309,136,307,137,305,137,303,139,
303,141,304,143,307,143,310,142,313,139,315,135,314,131,312,128,308,126,303,125,
299,126,293,128,290,131,288,135,288,139,290,144,292,147,296,151,299,155,301,159,
301,163,301,167,300,169,298,171};

int d2[30]={330,243,329,245,330,247,336,260,338,261,340,260,346,258,348,256,
350,253,351,250,351,245,349,242,347,239,343,239,339,239};

int d1[32]={307,252,313,264,315,266,318,267,326,265,329,263,330,261,331,257,
331,255,329,252,327,250,325,248,322,247,318,247,310,249,308,249};

int d3[12]={316,253,319,260,322,260,324,258,323,255,320,253};

int d4[16]={337,247,341,255,343,254,345,252,345,250,344,247,342,246,340,246};

setbkcolor(15);

setcolor(15);
setfillstyle(1,6);
fillpoly(16,sqr1);
fillpoly(10,small);

setcolor(15);
setfillstyle(1,13);
fillpoly(25,sqr2);

setcolor(6);
setfillstyle(1,6);
fillpoly(37,cup);
fillpoly(53,swirl1);
fillpoly(62,swirl2);

setcolor(15);
setfillstyle(1,15);
fillpoly(24,cup1);
fillpoly(24,cup2);
fillpoly(26,cup0);

setcolor(6);
setfillstyle(1,6);
fillpoly(16,d1);

setcolor(13);
setfillstyle(1,13);
fillpoly(15,d2);

setcolor(15);
setfillstyle(1,15);
fillpoly(6,d3);
fillpoly(8,d4);

				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "5");
settextstyle(2,0,10);
outtextxy(270,8," of 5");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}

/*********************************************************************************LOGO 16***************************/

void logo_16(){
	int part1[218]={293,233,316,234,328,234,341,233,350,233,356,234,358,235,
360,236,360,238,361,240,360,242,359,244,357,246,355,248,350,250,301,250,
298,250,296,248,294,247,293,245,294,243,295,240,264,241,261,247,260,251,
260,255,259,258,260,260,261,262,263,264,266,266,269,267,274,268,279,268,
286,268,291,269,307,268,331,268,344,267,352,266,358,266,363,265,368,264,
372,262,376,260,380,257,383,254,386,250,390,244,392,238,393,234,394,228,
393,225,392,222,391,220,388,218,384,216,379,215,361,215,314,214,311,214,
309,212,307,210,308,208,309,206,311,203,314,201,318,201,322,200,361,199,
365,199,367,200,369,201,370,202,370,204,371,205,370,208,400,208,401,206,
403,201,404,198,405,195,404,192,403,190,401,186,399,184,395,183,391,182,
387,181,379,181,326,181,321,181,316,181,310,183,306,183,300,185,293,187,
288,191,285,194,282,197,278,203,276,209,274,213,273,218,273,222,273,225,
274,227,276,230,279,232};

int part2[116]={406,214,410,217,412,220,413,224,414,226,414,231,412,239,
407,249,402,257,392,267,388,269,384,272,379,273,369,275,363,276,261,276,
254,275,249,274,244,272,241,270,237,266,235,262,235,258,235,254,236,248,
241,240,243,235,260,234,257,232,255,230,253,226,252,222,251,218,251,214,
252,210,254,205,256,201,260,196,262,191,267,186,274,181,281,178,286,176,
293,175,297,175,395,174,404,174,408,175,413,177,417,179,420,181,423,184,
424,187,426,192,426,194,425,199,422,206,418,214};

int part3[156]={423,215,426,217,429,220,430,222,431,225,432,228,432,231,
431,235,430,239,429,244,424,252,421,257,416,263,413,267,408,271,403,274,
399,276,394,278,387,279,380,280,374,280,292,281,255,281,248,281,242,281,
238,280,234,280,229,279,224,277,220,274,215,269,214,266,213,263,212,259,
213,255,214,252,217,245,223,234,237,234,236,232,234,228,232,224,232,219,
232,215,233,210,235,206,237,201,240,194,242,192,244,189,248,185,252,182,
257,179,261,176,266,174,270,173,276,171,281,170,289,170,296,170,306,169,
392,168,402,168,411,169,417,169,423,170,429,172,434,174,438,177,441,179,
444,182,446,186,446,190,446,195,445,199,443,204,439,210,437,214};

setbkcolor(15);

setcolor(8);
setfillstyle(1,8);
fillpoly(78,part3);

setcolor(15);
setfillstyle(1,15);
fillpoly(58,part2);

setcolor(1);
setfillstyle(1,1);
fillpoly(109,part1);

				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "6");
settextstyle(2,0,10);
outtextxy(270,8," of 6");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);

}

/*****************************************************************LOGO 17**************************************/

void logo_17(){
	
	int leaf1[60]={298,237,297,229,297,222,297,216,298,210,299,205,300,196,301,192,
302,186,304,180,307,172,310,166,313,159,316,154,320,149,323,145,327,141,
330,144,335,150,340,158,344,165,348,175,352,184,354,192,356,204,357,214,
357,223,356,231,356,237,298,237};
int leaf2[58]={361,237,365,231,368,227,373,220,376,218,380,215,383,212,386,209,
389,207,392,205,396,202,400,200,406,197,409,195,414,193,420,191,423,190,
428,188,434,187,440,187,439,192,439,199,438,204,437,210,435,216,432,223,
429,230,427,237,361,237};
int leaf3[44]={215,186,221,187,230,189,238,192,243,194,250,197,257,201,263,205,
269,210,274,214,279,218,283,222,289,229,293,237,227,237,224,231,222,225,
220,218,217,211,216,204,215,198,215,186};
int line1[10]={232,245,423,245,417,255,237,255,232,245};
int line2[14]={245,262,409,262,405,268,401,271,253,271,249,267,245,262};
int part1[16]={265,279,311,279,311,299,306,298,300,297,293,295,285,292,265,279};
int part2[20]={313,279,341,279,338,286,335,290,330,296,327,300,323,295,
320,291,316,286,313,279};
int part3[20]={343,279,389,279,383,284,378,287,372,290,364,294,356,296,
348,298,343,299,343,279};


setbkcolor(15);

setcolor(8);
setfillstyle(1,8);
fillpoly(30,leaf1);
fillpoly(29,leaf2);
fillpoly(22,leaf3);
fillpoly(5,line1);
fillpoly(7,line2);
fillpoly(8,part1);
fillpoly(10,part2);
fillpoly(10,part3);

				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "6");
settextstyle(2,0,10);
outtextxy(270,8," of 6");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}

/*********************************************************************************LOGO 18***************************/

void logo_18(){

setbkcolor(15);

setcolor(1);
rectangle(390,295,250,155);
rectangle(385,290,255,160);

setfillstyle(1,1);
bar(290,245,355,215);
bar(270,260,300,235);

sector(295,240,90,180,25,25);
sector(285,255,180,360,15,23);
sector(355,230,270,360,15,15);
sector(355,230,0,90,15,15);

setcolor(4);
setfillstyle(1,4);
bar(280,200,360,170);
sector(355,185,270,360,15,15);
sector(355,185,0,90,15,15);
sector(285,185,180,270,15,15);
sector(285,185,90,180,15,15);

				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "6");
settextstyle(2,0,10);
outtextxy(270,8," of 6");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}

/********************************************************************************LOGO 19*************************/
void logo_19(){
	int puma[266]={258,160,263,160,268,162,274,164,282,167,288,171,295,176,302,181,
308,186,313,190,319,195,325,200,332,205,340,209,349,214,356,217,361,219,367,219,
373,218,381,215,384,213,389,206,393,200,398,191,400,183,403,178,406,172,411,165,
415,161,423,155,428,151,431,151,435,151,438,154,439,158,438,162,437,165,434,168,
428,171,419,177,412,182,407,188,402,196,399,206,396,212,392,218,386,223,381,227,
384,230,387,236,389,245,390,253,390,263,391,270,392,276,396,280,402,285,403,293,
405,298,409,302,407,308,406,313,407,316,405,318,400,318,397,315,393,311,392,305,
391,291,386,287,380,281,375,275,369,268,363,259,361,253,357,246,355,241,351,237,
346,233,341,232,333,231,323,231,317,230,309,229,302,226,292,219,287,214,280,207,
278,207,275,210,269,213,266,213,259,213,255,212,241,205,238,204,235,204,234,206,
233,210,229,211,225,209,223,205,223,201,225,198,229,195,234,193,239,193,243,193,
247,194,251,192,250,187,247,183,245,183,242,184,239,185,237,185,234,182,231,180,
227,178,225,174,226,172,230,170,231,167,231,164,234,162,238,159,240,156,242,152,
244,155,247,156,251,154,252,151,254,156};

setbkcolor(15);
setcolor(8);
setfillstyle(1,8);
fillpoly(133,puma);
				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "6");
settextstyle(2,0,10);
outtextxy(270,8," of 6");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);


}

/**********************************************************************************LOGO 20***********************/
void logo_20(){
	
int m[26]={343,233,329,193,285,188,285,278,315,270,314,216,331,264,350,259,
362,219,361,255,374,252,374,201,352,198};

setbkcolor(15);

setcolor(14);
setfillstyle(1,14);
circle(320,230,70);
floodfill(320,240,14);

setcolor(8);
setfillstyle(1,15);
fillpoly(13,m);

				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "6");
settextstyle(2,0,10);
outtextxy(270,8," of 6");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
	
}

/********************************************************************************LOGO 21*************************/

void logo_21(){
	
	
int whole[130]={207,232,214,232,222,232,229,233,238,235,246,236,255,239,263,241,
270,244,277,248,284,252,288,255,293,258,298,262,302,267,305,272,308,276,
309,280,310,283,342,283,341,281,340,277,340,273,340,268,340,263,340,260,
340,257,342,254,344,250,346,248,348,246,351,243,354,240,358,238,364,235,
371,231,381,228,394,223,406,220,427,214,442,192,432,196,421,201,410,206,
397,211,383,215,369,219,355,223,343,226,333,228,321,231,313,233,303,233,
296,232,290,231,287,229,286,228,285,226,284,224,285,223,285,221,287,218,
291,213,299,205,207,232};
int part[32]={302,244,310,245,315,244,321,244,325,243,329,242,333,241,329,245,
327,249,324,254,322,259,321,263,318,258,314,254,310,250,302,244};

setbkcolor(15);

setcolor(8);
setfillstyle(1,8);
fillpoly(65,whole);

setcolor(15);
setfillstyle(1,15);
fillpoly(16,part);

				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "6");
settextstyle(2,0,10);
outtextxy(270,8," of 6");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
}


/****************************************************************************LOGO 22********************************************************************/
void logo_22(){
int box1[]={266, 133, 266, 314, 275, 311, 281, 308, 289, 305, 297, 303, 306, 301, 314, 302, 322, 303, 331, 302, 341, 301, 350, 300, 361, 299, 367, 298, 377, 295, 382, 294, 386, 292,
				386, 133, 266, 133};
	int g1[]={	  408, 160, 407, 162, 406, 164, 405, 166, 403, 169, 401, 172, 399, 174, 397, 176, 395, 178, 392, 180, 
				  389, 182, 387, 183, 385, 184, 383, 185, 381, 186, 378, 187, 377, 188, 374, 188, 373, 189, 369, 189, 
				  368, 190, 364, 190, 363, 191, 360, 191, 359, 192, 354, 192, 353, 193, 348, 193, 347, 194, 340, 194, 
				  339, 195, 335, 195, 334, 196, 315, 196, 314, 197, 305, 197, 304, 198, 297, 198, 296, 199, 290, 199, 
				  289, 200, 285, 200, 284, 201, 281, 202, 278, 203, 275, 204, 272, 205, 269, 206, 267, 207, 264, 208, 
				  262, 209, 260, 210, 257, 212, 254, 214, 251, 216, 248, 218, 246, 220, 244, 222, 242, 224, 241, 224,
				  243, 221, 245, 219, 247, 216, 249, 214, 251, 212, 254, 209, 257, 207, 260, 205, 262, 203, 265, 201,
				  267, 201, 268, 200, 271, 198, 275, 197, 279, 196, 280, 195, 282, 195, 283, 194, 287, 194, 288, 193,
				  290, 193, 291, 192, 296, 192, 297, 191, 302, 191, 303, 190, 307, 190, 308, 189, 313, 189, 314, 188,
				  334, 188, 335, 187, 339, 187, 340, 186, 354, 186, 355, 185, 360, 185, 361, 184, 367, 184, 368, 183,
				  372, 183, 373, 182, 376, 182, 377, 181, 380, 180, 383, 179, 386, 178, 388, 177, 391, 175, 393, 174,
				  395, 173, 397, 171, 399, 170, 401, 168, 403, 166, 405, 163, 406, 161, 408, 160};
	int g2[]={	  241, 305, 242, 302, 244, 298, 246, 295, 248, 292, 250, 290, 252, 288, 254, 286, 256, 284, 259, 281, 
				  261, 279, 264, 277, 267, 275, 270, 273, 272, 272, 274, 271, 276, 270, 278, 270, 279, 269, 281, 269,
				  282, 268, 284, 268, 285, 267, 287, 267, 288, 266, 290, 266, 291, 265, 293, 265, 294, 264, 296, 264, 
				  297, 263, 301, 263, 302, 262, 309, 262, 311, 261, 315, 261, 317, 260, 334, 260, 335, 259, 350, 259,
				  351, 258, 362, 258, 363, 257, 368, 257, 369, 256, 374, 256, 375, 255, 379, 255, 380, 254, 383, 254, 
				  384, 253, 387, 252, 390, 251, 393, 250, 395, 249, 397, 248, 400, 246, 402, 244, 404, 242, 406, 240,
				  408, 239, 407, 241, 405, 243, 404, 245, 403, 246, 401, 248, 398, 250, 396, 252, 393, 254, 390, 256,
				  387, 258, 384, 259, 381, 260, 378, 261, 375, 262, 372, 263, 371, 264, 367, 264, 366, 265, 361, 265,
				  360, 266, 351, 266, 350, 267, 341, 267, 340, 268, 322, 268, 321, 269, 314, 269, 313, 270, 307, 270,
				  306, 271, 301, 271, 296, 272, 292, 273, 288, 274, 284, 275, 281, 276, 278, 277, 275, 278, 272, 279,
				  268, 281, 264, 283, 261, 285, 258, 287, 255, 289, 252, 292, 250, 294, 247, 297, 245, 299, 244, 303,
				  241, 305};
				  
	int y1[]={	  241, 224,
				  243, 221, 245, 219, 247, 216, 249, 214, 251, 212, 254, 209, 257, 207, 260, 205, 262, 203, 265, 201,
				  267, 201, 268, 200, 271, 198, 275, 197, 279, 196, 280, 195, 282, 195, 283, 194, 287, 194, 288, 193,
				  290, 193, 291, 192, 296, 192, 297, 191, 302, 191, 303, 190, 307, 190, 308, 189, 313, 189, 314, 188,
				  334, 188, 335, 187, 339, 187, 340, 186, 354, 186, 355, 185, 360, 185, 361, 184, 367, 184, 368, 183,
				  372, 183, 373, 182, 376, 182, 377, 181, 380, 180, 383, 179, 386, 178, 388, 177, 391, 175, 393, 174,
				  395, 173, 397, 171, 399, 170, 401, 168, 403, 166, 405, 163, 406, 161, 408, 160, 406, 161, 404, 162,
				  401, 164, 399, 166, 396, 168, 393, 170, 390, 172, 387, 173, 383, 174, 382, 175, 378, 175, 377, 176, 
				  372, 176, 371, 177, 365, 177, 364, 178, 354, 178, 353, 179, 342, 179, 341, 180, 316, 180, 315, 181,
				  309, 181, 308, 182, 302, 182, 301, 183, 297, 183, 296, 184, 292, 184, 289, 185, 286, 186, 283, 187, 
				  280, 188, 277, 189, 273, 191, 272, 192, 269, 193, 266, 195, 264, 196, 262, 198, 259, 200, 257, 202,
				  254, 204, 252, 207, 249, 210, 247, 212, 246, 214, 244, 217, 242, 220, 241, 224};
	int y2[]={	  408, 239, 407, 241, 405, 243, 404, 245, 403, 246, 401, 248, 398, 250, 396, 252, 393, 254, 390, 256,
				  387, 258, 384, 259, 381, 260, 378, 261, 375, 262, 372, 263, 371, 264, 367, 264, 366, 265, 361, 265,
				  360, 266, 351, 266, 350, 267, 341, 267, 340, 268, 322, 268, 321, 269, 314, 269, 313, 270, 307, 270,
				  306, 271, 301, 271, 296, 272, 292, 273, 288, 274, 284, 275, 281, 276, 278, 277, 275, 278, 272, 279,
				  268, 281, 264, 283, 261, 285, 258, 287, 255, 289, 252, 292, 250, 294, 247, 297, 245, 299, 244, 303,
				  241, 305, 243, 303, 246, 301, 248, 299, 251, 297, 254, 295, 257, 293, 259, 291, 262, 289, 265, 288,
				  269, 286, 272, 285, 275, 284, 278, 283, 282, 282, 286, 281, 290, 281, 291, 280, 295, 280, 296, 279, 
				  303, 279, 304, 278, 313, 278, 314, 277, 334, 277, 335, 276, 344, 276, 345, 275, 352, 275, 353, 274,
				  358, 274, 359, 273, 363, 273, 364, 272, 367, 272, 370, 271, 372, 270, 375, 269, 377, 268, 380, 267,
				  382, 266, 385, 264, 388, 262, 391, 260, 394, 258, 396, 256, 399, 254, 401, 252, 403, 250, 404, 248,
				  405, 246, 406, 244, 407, 241, 408, 239
				  };
				  
	int layer1[]={241, 305, 242, 302, 244, 298, 246, 295, 248, 292, 250, 290, 252, 288, 254, 286, 256, 284, 259, 281, 
				  261, 279, 264, 277, 267, 275, 270, 273, 272, 272, 274, 271, 276, 270, 278, 270, 279, 269, 281, 269,
				  282, 268, 284, 268, 285, 267, 287, 267, 288, 266, 290, 266, 291, 265, 293, 265, 294, 264, 296, 264, 
				  297, 263, 301, 263, 302, 262, 309, 262, 311, 261, 315, 261, 317, 260, 334, 260, 335, 259, 350, 259,
				  351, 258, 362, 258, 363, 257, 368, 257, 369, 256, 374, 256, 375, 255, 379, 255, 380, 254, 383, 254, 
				  384, 253, 387, 252, 390, 251, 393, 250, 395, 249, 397, 248, 400, 246, 402, 244, 404, 242, 406, 240,
				  408, 239, 408, 160, 407, 162, 406, 164, 405, 166, 403, 169, 401, 172, 399, 174, 397, 176, 395, 178, 
				  392, 180, 389, 182, 387, 183, 385, 184, 383, 185, 381, 186, 378, 187, 377, 188, 374, 188, 373, 189,
				  369, 189, 368, 190, 364, 190, 363, 191, 360, 191, 359, 192, 354, 192, 353, 193, 348, 193, 347, 194, 
				  340, 194, 339, 195, 335, 195, 334, 196, 315, 196, 314, 197, 305, 197, 304, 198, 297, 198, 296, 199,
				  290, 199, 289, 200, 285, 200, 284, 201, 281, 202, 278, 203, 275, 204, 272, 205, 269, 206, 267, 207, 
				  264, 208, 262, 209, 260, 210, 257, 212, 254, 214, 251, 216, 248, 218, 246, 220, 244, 222, 242, 224,
				  241, 224, 241, 305};
	int k[]={247, 240, 246, 240, 245, 239, 245, 238, 246, 237, 246, 236, 247, 235, 247, 234, 248, 233, 249, 232, 250, 231, 251, 230, 252, 229, 253, 228, 254, 227, 255, 226, 256, 226, 257,
			 225, 258, 225, 259, 225, 260, 224, 261, 224, 262, 224, 262, 223, 263, 223, 264, 223, 265, 223, 266, 223, 266, 222, 267, 221, 268, 220, 269, 219, 270, 218, 271, 217, 271, 217,
			 277, 217, 278, 217, 279, 218, 280, 219, 280, 222, 280, 223, 279, 224, 279, 225, 278, 225, 277, 226, 276, 227, 275, 227, 274, 228, 273, 229, 273, 230, 272, 231, 271, 234, 271,
			 235, 271, 238, 272, 238, 273, 237, 274, 236, 275, 235, 276, 234, 277, 233, 278, 232, 278, 231, 279, 230, 280, 229, 281, 228, 281, 227, 282, 226, 283, 225, 284, 224, 284, 223,
			 285, 222, 286, 221, 287, 220, 287, 219, 288, 218, 289, 217, 290, 216, 291, 215, 292, 214, 293, 213, 294, 213, 295, 212, 296, 212, 297, 211, 300, 211, 300, 210, 304, 210, 304,
			 209, 311, 209, 312, 210, 311, 211, 310, 212, 306, 212, 306, 213, 303, 213, 303, 214, 302, 214, 301, 215, 300, 215, 299, 216, 298, 217, 297, 218, 296, 219, 295, 220, 295, 221,
			 294, 222, 293, 223, 293, 224, 292, 225, 291, 226, 291, 227, 290, 228, 289, 229, 288, 230, 288, 231, 287, 232, 286, 233, 285, 234, 284, 235, 283, 236, 282, 237, 281, 237, 280,
			 238, 279, 238, 279, 239, 277, 239, 277, 241, 278, 241, 279, 242, 282, 245, 284, 245, 285, 245, 285, 244, 286, 244, 287, 243, 288, 242, 288, 241, 289, 240, 290, 239, 291, 238,
			 291, 237, 292, 236, 293, 235, 293, 234, 294, 233, 292, 232, 295, 231, 295, 240, 294, 241, 293, 242, 292, 244, 291, 246, 285, 252, 284, 253, 282, 253, 282, 254, 279, 254, 278,
			 254, 270, 246, 268, 246, 268, 249, 267, 250, 267, 255, 266, 255, 266, 259, 265, 259, 265, 261, 263, 263, 262, 263, 261, 264, 260, 264, 259, 265, 258, 265, 257, 266, 256, 267,
			 254, 267, 254, 262, 255, 261, 255, 259, 256, 258, 256, 255, 257, 254, 257, 251, 258, 250, 258, 247, 257, 247, 256, 246, 256, 243, 259, 240, 260, 240, 261, 239, 261, 238, 262,
			 237, 262, 235, 263, 234, 263, 230, 260, 230, 259, 231, 257, 231, 256, 232, 255, 232, 254, 233, 248, 239, 247, 240 };

				
	setbkcolor(15); 
	setfillstyle(SOLID_FILL, 2);	fillpoly (18, box1);
	fillpoly (118, g1);
	fillpoly (111, g2);
	setfillstyle(SOLID_FILL, 15);	fillpoly(122, layer1);
	setfillstyle(SOLID_FILL, 4);	fillpoly (198, k);
	setfillstyle(SOLID_FILL, 14);	fillpoly(119, y1);
	fillpoly (104, y2);
	
	
	
					//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "7");
settextstyle(2,0,10);
outtextxy(270,8," of 7");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);

setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);
}

/****************************************************************************LOGO 23***************************************************/
void logo_23(){
	
	int balloon[]={324, 279, 319, 273, 314, 268, 310, 265, 304, 262, 295, 259, 288, 257, 282, 256, 276, 255, 267, 252, 260, 251, 255, 250, 247, 248, 241, 245, 236, 243, 232, 240, 225, 236
				  ,220, 230, 217, 225, 216, 220, 216, 215, 218, 209, 220, 203, 223, 197, 227, 194, 233, 190, 239, 187, 245, 184, 253, 181, 261, 179, 268, 177, 274, 175, 282, 173, 288, 172
				  ,295, 172, 307, 171, 315, 170, 319, 170, 328, 170, 335, 171, 342, 171, 347, 172, 352, 173, 359, 174, 365, 175, 372, 176, 380, 178, 385, 179, 393, 181, 399, 184, 410, 189
				  ,417, 192, 421, 196, 426, 202, 430, 208, 431, 216, 430, 222, 428, 230, 425, 233, 420, 238, 415, 242, 410, 244, 404, 246, 399, 248, 393, 250, 386, 251, 379, 253, 375, 254
				  ,370, 255, 365, 257, 360, 258, 353, 260, 348, 262, 343, 264, 337, 267, 334, 269, 331, 273, 324, 279};
		  int m[]={246, 201, 246, 227, 253, 227, 253, 212, 262, 227,  269, 227, 270, 227, 278, 212 , 278, 227, 286, 227, 286, 201, 275, 201, 267, 217, 258, 201, 246, 201};

setbkcolor(15);
setfillstyle(SOLID_FILL, 4);	fillpoly (78, balloon);
setfillstyle(SOLID_FILL, 14);	fillpoly (15, m);
	
					//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "7");
settextstyle(2,0,10);
outtextxy(270,8," of 7");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
	
}
/****************************************************************************LOGO 24***************************************************/
void logo_24(){
	
	int nose[50]=
{335,262,336,263,337,263,338,264,339,264,340,265,351,265,352,264,354,264,358,260,
358,255,356,253,355,253,354,252,351,252,350,253,353,256,353,260,352,261,351,261,
350,262,340,262,339,261,336,261,335,262};
int mouth[186]=
{301,272,302,271,305,271,306,270,308,270,310,268,311,268,313,266,314,267,314,268,
313,269,313,271,316,271,317,272,321,272,322,273,347,273,348,272,351,272,352,271,
354,271,355,270,357,270,358,269,359,269,360,268,361,268,362,267,363,267,365,265,
366,265,374,257,374,255,372,255,370,253,371,252,381,252,382,253,381,254,380,254,
374,260,374,261,371,264,371,265,369,267,369,268,367,270,367,271,366,272,366,273,
364,275,364,276,363,277,363,278,362,279,362,280,361,281,361,282,358,285,357,285,
356,286,355,286,354,287,342,287,341,286,339,286,338,285,336,285,335,284,334,284,
333,283,332,283,330,281,329,281,328,280,327,280,325,278,324,278,323,277,322,277,
321,276,319,276,318,275,316,275,315,274,313,274,312,273,310,273,309,272,306,272,
305,273,302,273,301,272};
int tongue[46]=
{336,281,336,280,338,278,343,278,344,279,348,279,349,280,350,280,350,277,351,276,
356,276,357,277,358,277,359,278,359,280,355,284,354,284,353,285,344,285,343,284,
340,284,338,282,337,282};
int lefteye[114]=
{304,259,304,258,302,256,302,255,300,253,300,252,299,251,299,250,298,249,298,248,
297,247,297,245,296,244,296,241,295,240,295,230,296,229,296,227,297,226,297,225,
298,224,298,223,300,221,301,221,302,220,303,220,304,219,306,219,307,218,312,218,
313,219,315,219,316,220,317,220,318,221,320,221,326,227,326,228,328,230,328,231,
330,233,330,235,331,236,331,238,332,239,332,253,333,254,332,255,331,255,330,256,
318,256,317,257,312,257,311,258,308,258,307,259,304,259};
int leftpupil[84]=
{296,244,301,239,301,238,303,236,304,236,305,235,314,235,315,236,315,238,314,239,
314,241,313,242,314,243,315,242,316,242,318,240,319,240,320,241,320,242,321,243,
321,244,322,245,322,256,318,256,317,257,312,257,311,258,308,258,307,259,304,259,
304,258,302,256,302,255,300,253,300,252,299,251,299,250,298,249,298,248,297,247,
297,245,296,244};
int righteye[120]=
{355,248,350,243,350,242,349,241,349,240,347,238,347,236,346,235,346,234,345,233,
345,231,344,230,344,219,345,218,345,217,346,216,346,215,347,214,347,213,351,209,
352,209,355,208,356,207,358,207,359,208,362,208,363,209,365,209,372,216,372,217,
373,218,373,219,374,220,374,221,375,222,375,224,376,225,376,229,377,230,377,239,
376,239,375,240,374,240,373,241,371,241,370,242,369,242,368,243,366,243,365,244,
364,244,363,245,362,245,361,246,359,246,358,247,357,247,356,248,356,248,355,248};
int rightpupil[82]=
{345,232,353,224,359,224,360,225,361,225,362,226,362,229,361,230,361,231,360,232,
361,233,362,232,363,232,364,231,366,231,367,232,367,234,368,235,368,243,366,243,
365,244,364,244,363,245,362,245,361,246,359,246,358,247,357,247,356,248,356,248,
355,248,350,243,350,242,349,241,349,240,347,238,347,236,346,235,346,234,345,233,
345,232};
int face[380]=
{292,256,291,255,291,254,289,252,289,251,288,250,288,249,287,248,287,246,286,245,
286,243,285,242,285,240,284,239,284,225,285,224,285,222,286,221,286,220,289,217,
289,216,292,213,293,213,294,212,295,212,296,211,297,211,298,210,300,210,301,209,
303,209,304,208,312,208,313,209,312,209,317,210,319,210,321,212,322,212,323,213,
324,213,328,217,329,217,335,223,336,222,336,217,337,216,337,213,338,212,338,210,
339,209,339,208,344,203,345,203,346,202,347,202,348,201,350,201,351,200,361,200,
362,201,364,201,366,203,367,203,369,205,370,205,374,209,374,210,376,212,376,213,
377,214,377,215,378,216,378,217,379,218,379,219,380,220,380,223,381,224,381,226,
382,227,382,234,383,235,384,234,386,234,387,233,395,233,396,234,397,234,402,239,
402,241,403,242,403,243,404,244,404,259,403,260,403,262,402,263,402,264,401,265,
401,266,399,268,399,269,397,271,397,272,380,289,379,289,374,294,373,294,373,293,
372,292,371,293,371,294,369,296,369,297,366,300,365,300,362,303,361,303,360,304,
359,304,358,305,357,305,356,306,339,306,338,305,336,305,335,304,332,304,331,303,
330,303,329,302,328,302,327,301,325,301,328,304,329,304,330,305,331,306,326,306,
325,305,314,305,313,304,307,304,306,303,302,303,301,302,297,302,296,301,294,301,
293,300,290,300,289,299,287,299,286,298,284,298,283,297,282,297,281,296,280,296,
279,295,278,295,276,293,275,293,273,291,272,291,266,285,266,284,264,282,264,281,
263,280,263,279,262,278,262,276,261,275,261,270,262,269,262,266,263,265,263,264,
267,260,268,260,270,258,271,258,272,257,275,257,276,256,287,256,288,257,291,257};
int redcap[460]=
{287,256,288,257,291,257,292,256,291,255,291,254,289,252,289,251,288,250,288,249,
287,248,287,246,286,245,286,243,285,242,285,240,284,239,284,225,285,224,285,222,
286,221,286,220,289,217,289,216,292,213,293,213,294,212,295,212,296,211,297,211,
298,210,300,210,301,209,303,209,304,208,312,208,313,209,312,209,317,210,319,210,
321,212,322,212,323,213,324,213,328,217,329,217,335,223,336,222,336,217,337,216,
337,213,338,212,338,210,339,209,339,208,344,203,345,203,346,202,347,202,348,201,
350,201,351,200,361,200,362,201,364,201,366,203,367,203,369,205,370,205,374,209,
374,210,376,212,376,213,377,214,377,215,378,216,378,217,379,218,379,219,380,220,
380,223,381,224,381,226,382,227,382,234,383,235,384,234,387,231,387,227,386,226,
386,221,385,220,385,219,384,218,384,217,383,216,383,215,381,213,381,212,380,211,
380,210,379,209,379,208,378,207,378,206,374,202,374,201,373,200,372,200,367,195,
366,195,365,194,364,194,363,193,362,193,361,192,359,192,358,191,357,191,356,190,
357,189,357,186,358,185,358,184,359,183,359,181,360,180,360,179,361,178,361,176,
365,172,365,171,370,166,370,165,372,163,372,160,370,158,366,158,365,159,364,159,
359,164,359,165,357,167,357,168,356,169,356,170,355,171,355,172,354,173,354,175,
353,176,353,180,352,181,352,187,351,188,347,188,346,187,343,187,342,186,336,186,
335,185,320,185,319,186,315,186,314,187,312,187,311,188,308,188,307,189,305,189,
304,190,303,190,302,191,300,191,299,192,298,192,296,190,296,188,295,187,295,184,
294,183,294,176,295,175,295,174,296,173,296,164,294,162,291,162,289,164,289,165,
288,166,288,167,287,168,287,181,288,182,288,187,289,188,289,189,290,190,290,192,
291,193,291,194,292,195,292,196,291,197,290,197,289,198,288,198,287,199,286,199,
274,211,274,212,272,214,272,215,271,216,271,217,270,218,270,219,268,221,268,223,
267,224,267,231,266,232,266,242,267,243,267,253,271,257,275,257,276,256,287,256};
int hat[302]=
{336,186,336,178,335,177,335,174,334,173,334,168,336,166,337,166,348,155,348,154,
349,153,349,152,350,151,350,150,351,149,351,146,352,145,352,139,351,138,351,135,
350,134,350,133,349,132,349,131,343,125,342,125,341,124,339,124,338,123,336,123,
335,122,322,122,321,123,318,123,317,124,316,124,315,125,313,125,312,126,311,126,
310,127,309,127,308,128,307,128,305,130,304,130,302,132,301,132,296,137,295,137,
286,146,286,147,282,151,282,152,281,153,278,153,277,154,271,154,270,155,266,155,
265,156,262,156,261,157,258,157,257,158,254,158,253,159,252,159,251,160,249,160,
247,162,246,162,245,163,244,163,242,165,241,165,237,169,237,170,236,171,236,172,
235,173,235,174,234,175,234,177,233,178,233,185,234,186,234,188,235,189,235,190,
243,198,244,198,245,199,247,199,248,200,251,200,252,201,262,201,263,200,267,200,
276,209,286,199,287,199,288,198,289,198,290,197,291,197,292,196,292,195,291,194,
290,192,290,190,289,189,289,188,288,187,288,182,287,181,287,168,288,167,288,166,
289,165,289,164,291,162,294,162,296,164,296,173,295,174,295,175,294,176,294,183,
295,184,295,187,296,188,296,190,298,192,299,192,300,191,302,191,303,190,304,190,
305,189,307,189,308,188,311,188,312,187,314,187,315,186,319,186,320,185,335,185,
336,186};
int gd=DETECT,gm;

setcolor(15);
setfillstyle(SOLID_FILL, 15);
fillpoly(60,righteye);
fillpoly(57,lefteye);
fillpoly(151,hat);
fillpoly(190,face);

setfillstyle(SOLID_FILL, 4);
fillpoly(23,tongue);
fillpoly(230,redcap);

setfillstyle(SOLID_FILL, 0);
fillpoly(25,nose);
fillpoly(93,mouth);
fillpoly(42,leftpupil);
fillpoly(41,rightpupil);
	
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "7");
settextstyle(2,0,10);
outtextxy(270,8," of 7");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
	
}
/****************************************************************************LOGO 25***************************************************/
void logo_25(){
	
	setcolor(BLACK);
	int outline[]={313, 156, 392, 144, 371, 170, 387, 168, 259, 295, 313, 191, 297, 191, 313, 156};
	int black[]={392, 144, 397, 150, 381, 168, 389, 168, 393, 173, 262, 302, 259, 295, 387, 168, 371, 170, 392, 144};
	int black2[]={313, 191, 297, 191, 300, 198, 310, 197, 313, 191};
	
setbkcolor(15);
setcolor(8);
setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
setfillstyle(SOLID_FILL, 4);	fillpoly(8, outline);
setfillstyle(SOLID_FILL, 0);	fillpoly (10, black); //ayaw ng black
fillpoly (5, black2);
	
					//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "7");
settextstyle(2,0,10);
outtextxy(270,8," of 7");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
	
}
/****************************************************************************LOGO 26***************************************************/
void logo_26(){
	
	int k1[]={268, 196, 274, 193, 282, 192, 289, 188, 297, 181, 306, 176, 315, 172, 322, 167, 331, 161, 338, 157, 344, 154, 348, 155, 351, 158, 349, 162, 329, 192, 289, 262, 283, 271
			 ,276, 279, 271, 283, 266, 286, 261, 287, 255, 287, 249, 284, 246, 277, 246, 273, 247, 270, 249, 265, 253, 258, 259, 252, 266, 246, 272, 240, 279, 235, 287, 228, 292, 222
			 ,296, 215, 301, 210, 305, 204, 308, 198, 309, 195, 307, 192, 304, 193, 301, 195, 297, 198, 292, 202, 287, 208, 281, 216, 276, 221, 272, 224, 268, 227, 262, 229, 257, 228
			 ,253, 224, 250, 219, 251, 213, 254, 207, 257, 203, 262, 200, 268, 196};
	int k2[]={318, 222, 327, 208, 333, 204, 339, 201, 346, 195, 353, 188, 358, 183, 364, 178, 369, 171, 376, 164, 385, 152, 391, 145, 397, 138, 404, 132, 411, 130, 417, 130, 423, 134
			 ,425, 140, 423, 149, 418, 157, 412, 164, 406, 170, 399, 178, 391, 183, 383, 189, 376, 194, 370, 199, 362, 204, 355, 208, 350, 212, 340, 217, 342, 225, 343, 232, 342, 242
			 ,340, 251, 338, 260, 337, 269, 335, 277, 334, 284, 335, 291, 339, 297, 341, 299, 339, 304, 334, 306, 329, 307, 322, 305, 317, 303, 312, 300, 310, 296, 307, 288, 306, 282
			 ,307, 287, 307, 271, 308, 267, 310, 263, 311, 257, 314, 252, 316, 246, 319, 240, 320, 234, 320, 229, 319, 227, 318, 222};
	
	
	setbkcolor(15);
	setfillstyle(SOLID_FILL, 4);	fillpoly (58, k1);
	setfillstyle(SOLID_FILL, 4);	fillpoly (63, k2);
	
					//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "2");
settextstyle(2,0,10);
outtextxy(270,8," of 7");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
	
}
/****************************************************************************LOGO 27***************************************************/
void logo_27(){
	setcolor(BLACK);
		int green[]={260, 167, 375, 133, 410, 238, 296, 273, 260, 167};
	int pink[]={226, 259, 435, 259, 435, 308, 226, 308, 226, 259};
	 
setbkcolor(15);
setfillstyle(SOLID_FILL, 13);	fillpoly (5, pink);
setfillstyle(SOLID_FILL, 10);	fillpoly (5, green);
 setcolor(15); 	//settextstyle(1, 0, 30); 	outtextxy (305, 95, "g");

	
				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "7");
settextstyle(2,0,10);
outtextxy(270,8," of 7");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
	
}

/****************************************************************************LOGO 28***************************************************/
void logo_28(){
	
		int green[]={218, 269, 218, 272, 219, 273, 219, 275, 257, 275, 259, 274, 260, 274, 261, 273, 262, 273, 263, 272, 264, 271, 267, 268, 267, 266, 268, 265, 268, 257, 267, 256, 267, 254, 
				 266, 253, 266, 250, 265, 249, 265, 248, 264, 247, 264, 245, 263, 244, 263, 242, 262, 241, 262, 240, 261, 239, 261, 237, 260, 236, 260, 234, 259, 233, 259, 231, 258, 230, 
				 258, 228, 257, 227, 257, 226, 256, 225, 257, 224, 258, 223, 259, 223, 260, 222, 261, 222, 263, 221, 265, 220, 267, 219, 270, 218, 273, 217, 276, 216, 279, 215, 282, 214, 
				 285, 213, 288, 213, 289, 212, 292, 212, 293, 211, 297, 211, 298, 210, 302, 210, 303, 209, 310, 209, 311, 208, 345, 208, 350, 209, 355, 209, 358, 210, 365, 210, 368, 211, 
				 371, 212, 374, 213, 377, 215, 380, 216, 383, 217, 386, 217, 389, 218, 392, 219, 395, 220, 397, 221, 399, 222, 401, 223, 403, 224, 403, 226, 402, 229, 401, 232, 400, 235, 
				 399, 238, 398, 240, 397, 242, 396, 245, 395, 247, 394, 250, 393, 253, 392, 255, 392, 264, 393, 266, 394, 268, 395, 270, 397, 272, 399, 273, 401, 274, 403, 275, 440, 275, 
				 441, 274, 441, 272, 442, 270, 405, 270, 403, 269, 401, 268, 399, 266, 398, 263, 398, 259, 398, 257, 399, 255, 400, 251, 401, 249, 402, 247, 403, 245, 404, 242, 405, 239, 
				 406, 236, 407, 233, 408, 230, 409, 227, 410, 225, 411, 223, 411, 221, 410, 220, 407, 219, 405, 218, 402, 217, 400, 216, 397, 215, 395, 214, 393, 213, 391, 212, 388, 211, 
				 385, 210, 381, 209, 378, 208, 374, 207, 371, 206, 365, 205, 361, 204, 355, 203, 349, 202, 311, 202, 306, 203, 301, 204, 296, 205, 292, 206, 288, 207, 283, 208, 280, 209, 
				 277, 210, 273, 211, 270, 212, 267, 213, 264, 214, 262, 215, 260, 216, 258, 217, 256, 218, 254, 219, 252, 220, 250, 221, 249, 222, 250, 226, 251, 229, 252, 232, 253, 235, 
				 254, 239, 255, 242, 256, 245, 257, 248, 258, 251, 259, 254, 260, 256, 261, 257, 261, 264, 260, 265, 259, 267, 258, 268, 218, 268, 218, 269};
	int brown[]={442, 270, 405, 270, 403, 269, 401, 268, 399, 266, 398, 263, 398, 259, 398, 257, 399, 255, 400, 251, 401, 249, 402, 247, 403, 245, 404, 242, 405, 239, 406, 236, 407, 233,
				 408, 230, 409, 227, 410, 225, 411, 223, 411, 221, 410, 220, 407, 219, 405, 218, 402, 217, 400, 216, 397, 215, 395, 214, 393, 213, 391, 212, 388, 211, 385, 210, 381, 209, 
				 378, 208, 374, 207, 371, 206, 365, 205, 361, 204, 355, 203, 349, 202, 311, 202, 306, 203, 301, 204, 296, 205, 292, 206, 288, 207, 283, 208, 280, 209, 277, 210, 273, 211, 
				 270, 212, 267, 213, 264, 214, 262, 215, 260, 216, 258, 217, 256, 218, 254, 219, 252, 220, 250, 221, 249, 222, 250, 226, 251, 229, 252, 232, 253, 235, 254, 239, 255, 242, 
				 256, 245, 257, 248, 258, 251, 259, 254, 260, 256, 261, 257, 261, 264, 260, 265, 259, 267, 258, 268, 218, 268, 218, 269, 217, 267, 217, 265, 216, 264, 216, 261, 250, 261, 
				 251, 260, 252, 260, 253, 259, 253, 257, 253, 256, 252, 254, 251, 252, 250, 249, 249, 247, 248, 244, 247, 242, 246, 239, 245, 236, 244, 233, 243, 230, 242, 228, 241, 225, 
				 240, 222, 239, 220, 238, 218, 238, 217, 239, 216, 241, 215, 244, 214, 246, 213, 248, 212, 250, 211, 252, 210, 254, 209, 258, 207, 261, 206, 264, 205, 266, 204, 270, 203, 
				 273, 202, 276, 201, 279, 200, 282, 199, 285, 198, 289, 197, 293, 196, 299, 195, 304, 194, 311, 194, 313, 193, 343, 193, 344, 194, 349, 194, 350, 195, 355, 195, 356, 196, 
				 361, 196, 362, 197, 367, 197, 368, 198, 372, 198, 373, 199, 376, 199, 377, 200, 380, 200, 383, 201, 386, 202, 390, 203, 393, 204, 396, 205, 399, 206, 402, 207, 405, 208, 
				 408, 209, 410, 210, 412, 211, 414, 212, 417, 213, 419, 214, 421, 216, 421, 218, 420, 221, 419, 224, 418, 227, 417, 230, 416, 232, 415, 235, 414, 238, 413, 241, 412, 244, 
				 411, 247, 410, 250, 409, 252, 408, 254, 407, 256, 407, 258, 408, 259, 409, 260, 444, 260, 444, 263, 443, 264, 443, 266, 442, 267, 442, 270};
	int h[]={	 268, 230, 269, 229, 271, 229, 272, 228, 273, 228, 274, 227, 277, 227, 277, 230, 278, 231, 278, 233, 279, 234, 279, 236, 280, 237, 280, 238, 283, 238, 284, 237, 286, 237, 
				 287, 236, 287, 233, 286, 232, 286, 229, 285, 228, 285, 226, 284, 225, 284, 224, 286, 224, 287, 223, 289, 223, 290, 222, 292, 222, 292, 224, 293, 227, 294, 230, 295, 234, 
				 296, 237, 297, 241, 298, 245, 299, 249, 300, 252, 301, 253, 300, 254, 298, 255, 295, 256, 293, 256, 293, 254, 292, 253, 292, 251, 291, 249, 290, 246, 289, 243, 286, 243, 
				 285, 244, 283, 245, 283, 246, 284, 249, 285, 252, 286, 255, 287, 257, 287, 258, 285, 259, 282, 260, 279, 261, 279, 258, 278, 257, 277, 254, 276, 251, 275, 248, 274, 245, 
				 273, 242, 272, 239, 271, 237, 270, 234, 268, 230};
	int e[]={    299, 221, 301, 220, 306, 220, 307, 219, 311, 219, 314, 218, 318, 218, 319, 218, 319, 225, 318, 224, 313, 224, 312, 225, 308, 225, 308, 231, 309, 232, 311, 232, 313, 231, 
				 317, 231, 317, 238, 310, 238, 310, 246, 315, 246, 316, 245, 319, 245, 320, 244, 322, 244, 322, 251, 317, 251, 316, 252, 310, 252, 309, 253, 304, 253, 304, 247, 303, 246, 
				 303, 242, 302, 240, 302, 236, 301, 234, 301, 229, 300, 228, 300, 224, 299, 222, 299, 221};
	int z[]={	 372, 223, 373, 223, 376, 224, 377, 224, 380, 225, 383, 226, 386, 227, 389, 228, 390, 229, 390, 231, 391, 232, 391, 235, 389, 237, 386, 239, 383, 242, 379, 245, 376, 248, 
				 375, 249, 374, 249, 373, 250, 373, 251, 374, 252, 376, 252, 378, 253, 381, 253, 382, 254, 384, 254, 384, 255, 383, 257, 382, 259, 380, 261, 378, 260, 375, 259, 372, 258, 
				 369, 257, 366, 256, 364, 255, 364, 249, 367, 246, 370, 243, 373, 241, 376, 238, 380, 235, 383, 233, 380, 232, 379, 232, 377, 231, 376, 231, 373, 230, 370, 230, 370, 227, 
				 370, 226, 371, 225, 371, 224, 372, 223};
	
	setbkcolor(15); 
	setfillstyle(SOLID_FILL, 2); fillpoly (184, green);
	setfillstyle(SOLID_FILL, 2); fillpoly (184, brown); /* brown dapat to */
	setfillstyle(SOLID_FILL, 0); fillpoly (73, h);
	setfillstyle(SOLID_FILL, 0); fillpoly (43, e);
	setfillstyle(SOLID_FILL, 0); fillpoly (55, z);
	

	
				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "7");
settextstyle(2,0,10);
outtextxy(270,8," of 7");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
	
}
/****************************************************************************LOGO 29***************************************************/
void logo_29(){
	

int outline[]={218, 184, 218, 276 , 218, 279, 219, 279, 220, 281, 221, 283, 223, 284, 226, 285, 429, 285, 431, 285, 434, 285, 437, 284, 438, 284, 441, 280, 441, 233, 441, 184,
					440, 180, 438, 178, 435, 176, 431, 177, 224, 177, 224, 178, 222, 177, 222, 179, 220, 180, 218, 184};
	int red[]={226, 285, 429, 285, 431, 285, 434, 285, 437, 284, 438, 284, 441, 280, 441, 233 , 341, 233 , 226, 285 };
	int blue[]={ 224, 177, 341, 233, 441, 233, 441, 184, 440, 180, 438, 178, 434, 176, 431, 177, 224, 177 };
	int star1[]= {235, 184, 236, 191, 242, 194, 236, 198, 235, 204, 229, 200, 223, 202, 225, 195, 223, 188, 230, 188, 235, 184 };
	int star2[]= {311, 221, 314, 228, 320, 230, 315, 234, 314, 240, 309, 237, 302, 239, 304, 232, 300, 226, 307, 225, 311, 221 };
	int star3[]= {234, 256, 235, 263, 242, 267, 236, 270, 235, 276, 230, 271, 222, 273, 226, 267, 223, 261, 229, 262, 234, 256 };
	int sun[]= {252, 224, 252, 218, 254, 217, 254, 213, 255, 208, 256, 208, 257, 213, 257, 216, 259, 218, 259, 223,
				260, 223, 265, 218, 269, 217, 274, 213, 275, 214, 271, 219, 269, 222, 266, 227,
				267, 228, 272, 228, 275, 230, 280, 231, 280, 232, 275, 233, 272, 235, 267, 235,
				266, 238, 269, 241, 271, 244, 275, 248, 274, 249, 269, 246, 265, 244, 260, 241,
				259, 241, 259, 246, 257, 249, 256, 254, 255, 254, 254, 249, 252, 246, 252, 241,
				251, 240, 247, 244, 242, 246, 239, 248, 238, 247, 240, 244, 242, 240, 246, 236,
				245, 235, 240, 235, 237, 233, 232, 232, 232, 231, 237, 230, 240, 228, 245, 228,
				246, 227, 241, 222, 240, 219, 236, 214, 237, 213, 242, 217, 245, 218, 250, 223, 252, 224};

setbkcolor(15);
setcolor(8);
setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
drawpoly (26, outline);
setfillstyle(SOLID_FILL, 4);		fillpoly (10, red);
setfillstyle(SOLID_FILL, 1);		fillpoly (9, blue); 
setfillstyle(SOLID_FILL, 14);		fillpoly (11, star1); 
fillpoly (11, star2);
fillpoly (11, star3);
fillpoly (67, sun);


setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);	

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "8");
settextstyle(2,0,10);
outtextxy(270,8," of 8");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);


}


/*****************************************************************************LOGO 30******************************/
logo_30(){
	
	int r1[]={227, 162, 297, 162, 297, 298, 227, 298, 227, 162};
	int r2[]={297, 162, 366, 162, 366, 298, 297, 298, 297, 162};
	int r3[]={366, 162, 434, 162, 434, 298, 366, 298, 366, 163};

	setbkcolor(15);
	setfillstyle(SOLID_FILL, 1);	fillpoly(5, r1);
	setfillstyle(SOLID_FILL, 15);	fillpoly(5, r2);
	setfillstyle(SOLID_FILL, 4);	fillpoly(5, r3);
	
	//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "8");
settextstyle(2,0,10);
outtextxy(270,8," of 8");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);

setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);
}
/********************************************************LOGO 31**************************************************/

void logo_31(){
	setcolor(BLACK);
	int a1[]={220, 160, 442, 160, 442, 206, 220, 206, 220, 160};
	int a2[]={220, 206, 442, 206, 442, 250 , 220, 250, 220, 106};
	int a3[]={220, 250, 442, 250, 442, 293, 220, 293, 220, 250};
	setbkcolor(15);
	setfillstyle(SOLID_FILL, 0);	fillpoly(5, a1); 
	setfillstyle(SOLID_FILL, 4);	fillpoly(5, a2);
	setfillstyle(SOLID_FILL, 14);	fillpoly(5, a3);
		//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "8");
settextstyle(2,0,10);
outtextxy(270,8," of 8");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);	

setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);
}

/*************************************************LOGO 32***************************************************/

void logo_32(){

setcolor(BLACK);
int red[]={220, 135, 445, 135, 445, 220, 220, 220, 220, 135};
	int white[]={220, 220, 445, 220, 445, 305, 220, 305, 220, 220};

	setbkcolor(8);
	setfillstyle(SOLID_FILL, 4);	fillpoly(5, red); 
	setfillstyle(SOLID_FILL, 15);	fillpoly(5, white);
	
	
			//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "8");
settextstyle(2,0,10);
outtextxy(270,8," of 8");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);	

setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);
	
}

/****************************************************************************LOGO 33**************************/
void logo_33(){
	
setcolor(BLACK);	
	int r1[]={227, 162, 297, 162, 297, 298, 227, 298, 227, 162};
	int r2[]={297, 162, 366, 162, 366, 298, 297, 298, 297, 162};
	int r3[]={366, 162, 434, 162, 434, 298, 366, 298, 366, 163};

	setbkcolor(15);
	setfillstyle(SOLID_FILL, GREEN);	fillpoly(5, r1);
	setfillstyle(SOLID_FILL, WHITE);	fillpoly(5, r2);
	setfillstyle(SOLID_FILL, RED);	fillpoly(5, r3);
	
			//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "8");
settextstyle(2,0,10);
outtextxy(270,8," of 8");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);	

setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);
}
/******************************************************************************LOGO 34****************************/
void logo_34(){
setcolor(BLACK);	
	
	int blue[]={212, 150, 440, 150, 440, 298, 212, 298, 212, 150};
	int cross[]={212, 208,282, 208, 282, 150, 313, 150, 313, 208, 440, 208, 440, 238, 313, 238, 313, 298, 282, 298, 282, 238, 212, 238, 212, 208};
	

	setbkcolor(15);
	setfillstyle(SOLID_FILL, 1);	fillpoly(5, blue); 
	setfillstyle(SOLID_FILL, 14);	fillpoly(13, cross);
	
			//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "8");
settextstyle(2,0,10);
outtextxy(270,8," of 8");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);

setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);	
}

/*************************************************************************LOGO 35*************************************/

void logo_35(){
	
	setcolor(BLACK);
	int R1[]={220, 160, 442, 160, 442, 206, 220, 206, 220, 160};
	int R2[]={220, 206, 442, 206, 442, 250 , 220, 250, 220, 106};
	int R3[]={220, 250, 442, 250, 442, 293, 220, 293, 220, 250};
	int black[]={220, 160, 276, 206, 276, 250, 220, 293, 220, 160};

	setbkcolor(15);
	setfillstyle(SOLID_FILL, 2);	fillpoly(5, R1);
	setfillstyle(SOLID_FILL, 15);	fillpoly(5, R2);
	setfillstyle(SOLID_FILL, 4);	fillpoly(5, R3);
	setfillstyle(SOLID_FILL, 0);	fillpoly(5, black);
	
			//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "8");
settextstyle(2,0,10);
outtextxy(270,8," of 8");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);

setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);	
}

/****************************************************************************LOGO 36***************************************************/
void logo_36(){
	
	
	setcolor(BLACK);
	int a1[]={220, 160, 442, 160, 442, 206, 220, 206, 220, 160};
	int a2[]={220, 206, 442, 206, 442, 250 , 220, 250, 220, 106};
	int a3[]={220, 250, 442, 250, 442, 293, 220, 293, 220, 250};
	int w1[]={220, 198, 442, 198, 442, 207, 220, 207, 220, 198};
	int w2[]={220, 248, 442, 248, 442, 258, 220, 258, 220, 248};
	int ellipse[]={326, 179, 325, 179, 322, 181, 321, 182, 319, 184, 317, 186, 315, 188, 313, 190, 311, 192, 310, 194, 
				   308, 196, 301, 198, 306, 200, 305, 202, 304, 202, 304, 206, 303, 209, 302, 210, 302, 213, 301, 214,
				   301, 219, 300, 220, 300, 234, 301, 235, 301, 241, 302, 242, 302, 245, 303, 246, 303, 248, 304, 250,
				   305, 253, 307, 257, 309, 262, 311, 265, 313, 268, 315, 271, 317, 273, 319, 275, 321, 277, 323, 278,
				   325, 279, 326, 279, 328, 278, 330, 277, 332, 275, 333, 273, 335, 271, 338, 268, 340, 265, 342, 262, 
				   344, 257, 346, 253, 347, 250, 348, 248, 348, 246, 349, 245, 349, 242, 350, 241, 350, 235, 351, 234,
				   351, 220, 350, 219, 350, 214, 349, 213, 349, 210, 348, 209, 347, 206, 346, 204, 345, 202, 344, 200,
				   343, 198, 341, 196, 339, 194, 338, 192, 337, 190, 335, 188, 333, 186, 331, 184, 329, 182, 328, 181,
				   326, 179};
	int ellipse2[]={324, 222, 323, 223, 322, 224, 321, 225, 321, 231, 322, 232, 323, 233, 324, 234, 327, 234, 328, 233, 
					329, 232, 330, 231, 330, 225, 329, 224, 328, 223, 327, 222, 324, 222};
	int line1[]={300, 277, 347, 191};
	int line2[]={351, 277, 304, 191};
	int ahead1[]={296, 176, 302, 193, 304, 191, 307, 190, 296, 176};
	int ahead2[]={355, 176, 349, 193, 347, 191, 344, 190, 355, 176};
	int sc1[]={328, 215, 329, 213, 330, 211, 331, 209, 332, 205, 332, 196, 331, 192, 330, 189, 329, 187, 328, 185, 328, 215};
	int sc2[]={322, 185, 322, 215, 321, 213, 320, 211, 319, 209, 318, 205, 318, 196, 319, 192, 320, 189, 321, 187, 322, 185};
	int sc3[]={328, 242, 329, 244, 330, 246, 331, 249, 332, 253, 332, 261, 331, 266, 330, 269, 329, 271, 328, 272, 328, 242};
	int sc4[]={322, 242, 322, 272, 321, 271, 320, 269, 319, 266, 318, 261, 318, 253, 319, 249, 320, 246, 321, 244, 322, 242};
	int Eleft[]={304, 206, 303, 209, 302, 210, 302, 213, 301, 214, 301, 219, 300, 220, 300, 234, 301, 235, 301, 241, 302, 242, 
				 302, 245, 303, 246, 303, 248, 304, 250, 305, 248, 305, 246, 306, 245, 306, 242, 307, 241, 307, 235, 308, 234,
				 308, 220, 307, 219, 307, 214, 306, 213, 306, 210, 305, 209, 304, 206};
	int Eright[]={347, 250, 348, 248, 348, 246, 349, 245, 349, 242, 350, 241, 350, 235, 351, 234, 351, 220, 350, 219, 350, 214, 
				  349, 213, 349, 210, 348, 209, 347, 206, 346, 209, 345, 210, 345, 213, 344, 214, 344, 219, 343, 220, 343, 234,
				  344, 235, 344, 241, 345, 242, 345, 245, 346, 246, 346, 248, 347, 250};
	
	setbkcolor(15);
	setfillstyle(SOLID_FILL, 1);	fillpoly(5, a1); //ayaw gumana sakin ng black//
	setfillstyle(SOLID_FILL, 13);	fillpoly(5, a2);
	setfillstyle(SOLID_FILL, 2);	fillpoly(5, a3);
	setfillstyle(SOLID_FILL, 15);	fillpoly(5, w1);
	fillpoly(5, w2);
	setlinestyle(SOLID_LINE, 15, THICK_WIDTH); drawpoly(2, line1);
	drawpoly(2, line2);	
	setfillstyle(SOLID_FILL, 15);	fillpoly(5, ahead1);
	fillpoly(5, ahead2);
	setfillstyle(SOLID_FILL, 13);	fillpoly (81, ellipse);
	setfillstyle(SOLID_FILL, 15); fillpoly (17, ellipse2);
	fillpoly (11, sc1);
	fillpoly (11, sc2);
	fillpoly (11, sc3);
	fillpoly (11, sc4);
	setfillstyle(SOLID_FILL, 0);	fillpoly (27, Eleft);
	fillpoly (27, Eright);
	

	
				//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);

//texts
settextstyle(2,0,7);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,13, "LEVEL");
outtextxy(30,38, "8");
settextstyle(2,0,10);
outtextxy(270,8," of 8");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);


}



/*****************************************************GAME OVER**********************************************************/

void gameOver(){
	int bear1[152]={108,300,108,286,108,266,110,251,112,239,115,226,117,220,
118,217,115,212,114,208,115,202,117,198,121,194,126,194,130,197,132,198,
138,193,150,186,158,184,165,183,174,183,182,183,187,186,195,192,202,198,
208,205,212,214,216,221,217,226,222,227,227,230,233,236,238,244,232,268,
229,275,225,282,221,286,217,291,223,286,226,289,230,294,236,305,242,322,
222,323,221,326,218,333,214,341,211,344,205,348,200,350,194,350,189,348,
183,340,181,332,180,326,180,323,152,326,130,329,134,332,138,338,138,343,
139,348,138,353,135,360,129,364,120,365,114,364,106,361,101,356,96,351,
91,342,87,334,87,327,89,318,92,312,99,305};

int bear1hand[40]={87,336,89,342,93,348,98,353,103,358,110,363,116,364,
124,366,128,365,132,362,136,358,138,353,140,349,139,344,138,338,133,332,
124,326,119,324,114,324,112,324};

int bear1hand2[44]={217,296,214,296,210,294,204,295,199,297,191,301,187,307,
184,313,181,319,180,323,180,337,181,339,184,344,189,349,194,350,200,350,
207,348,211,343,217,337,220,331,223,321,223,314};

int bear1ear[20]={168,182,168,179,170,174,172,172,178,172,181,175,184,179,
185,183,185,185,180,183};

int bear1nose[26]={217,242,214,242,212,244,209,247,207,250,207,253,209,256,
214,255,217,251,222,247,224,245,223,242,220,241};

int bear1mouth[10]={192,287,194,285,197,285,199,285,199,287};
int bear1eye1[12]={188,238,187,241,190,244,192,244,193,241,192,239};
int bear1eye2[14]={211,228,210,231,212,234,215,233,215,230,215,228,213,227};

int bear2[58]={233,260,234,254,237,249,241,241,246,235,252,230,258,225,
266,220,275,217,283,216,295,215,306,217,317,221,327,228,335,236,341,244,
348,256,353,268,356,277,336,304,327,321,298,322,276,322,257,318,239,304,
234,298,233,291,231,282,231,270};

int bear2ear1[26]={233,258,230,257,227,254,227,249,227,245,231,241,233,238,
237,237,241,239,243,241,239,243,236,250,235,255};

int bear2ear2[14]={290,214,291,210,295,207,299,206,303,207,307,210,307,217};

int bear2hand1[62]={335,304,339,299,345,290,349,285,356,277,360,284,367,291,
371,297,375,305,378,312,378,316,376,324,373,329,366,335,359,338,351,341,
343,341,337,344,331,348,325,349,318,350,307,349,303,346,299,341,297,333,
297,326,300,317,304,312,309,308,315,306,326,303};

int bear2hand2[42]={236,305,240,302,245,299,254,299,259,299,266,304,270,310,
273,314,276,319,277,326,275,331,269,338,264,340,258,341,251,341,244,338,
239,334,234,329,232,323,232,315,233,310};

int bear2nose[24]={275,243,278,240,284,237,290,235,293,235,295,239,294,242,
291,243,286,246,282,248,279,247,276,246};

int bear2bump[20]={269,243,272,243,276,238,282,234,288,232,295,230,301,232,
307,233,313,238,318,245};

int bear2patch1[34]={250,245,247,251,245,256,245,262,247,266,251,268,255,268,
260,266,263,262,265,256,268,251,268,247,268,242,267,239,265,237,261,237,
257,238};

int bear2patch2[28]={285,232,283,229,281,227,282,224,285,221,292,220,299,220,
305,224,309,227,310,231,310,235,303,232,295,231,289,232};

int bear2mouth[10]={299,285,301,281,304,279,308,276,310,276};
int bear2eye1[12]={253,257,256,255,259,252,261,249,262,246,262,244};
int bear2eye2[12]={290,226,293,227,296,229,299,229,302,229,304,229};


int bear3[136]={359,281,363,274,368,269,378,260,386,254,386,249,386,243,
389,237,393,230,398,225,404,223,410,220,415,209,419,199,425,191,430,184,
437,179,447,174,456,171,464,170,472,170,480,171,488,174,492,171,496,171,
500,172,502,176,502,181,502,184,507,193,511,202,513,211,514,222,514,236,
513,247,510,262,509,270,506,279,503,284,512,285,519,288,525,290,530,294,
532,297,535,300,537,306,537,313,532,319,525,323,514,326,501,325,489,326,
476,322,473,322,467,326,458,331,450,332,435,333,427,332,418,330,409,327,
400,323,395,321,377,321,377,313,377,306,373,301,367,291};

int bear3hand[40]={471,284,478,282,485,282,494,282,506,284,516,286,524,289,
529,294,535,299,536,304,537,310,534,316,529,321,516,326,505,327,497,326,
487,324,477,323,469,321,460,318};

int bear3hand2[14]={511,260,518,262,523,263,525,265,523,288,515,286,505,284};

int bear3ear1[14]={440,176,439,173,439,169,443,165,447,164,451,164,455,169};

int bear3ear2[18]={485,182,486,177,487,174,491,171,496,171,499,173,501,177,
501,185,500,190};

int bear3nose[22]={401,236,401,240,403,242,408,246,412,248,416,248,417,246,
416,243,410,237,408,235,404,234};

int bear3mouth[6]={428,279,431,279,434,279};

int bear3bump[20]={386,249,386,254,388,259,390,263,394,269,399,277,404,281,
408,284,414,286,423,287};
int bear3eye1[12]={411,222,411,224,413,226,415,225,416,223,414,221};
int bear3eye2[14]={435,236,434,239,434,242,436,242,438,241,438,238,438,236};


int top[74]={89,341,74,351,71,359,71,367,71,386,77,405,83,408,100,394,
157,393,206,393,227,392,251,392,308,391,347,392,383,392,417,390,440,389,
467,389,484,390,488,390,490,386,491,383,485,373,506,361,509,357,509,354,
503,351,482,338,465,327,396,322,377,320,297,322,276,322,232,322,222,323,
180,324,129,329};

int left[28]={89,341,75,350,73,355,71,362,71,378,71,388,77,406,82,408,
90,400,100,394,96,393,96,388,103,360,94,349};

int right[18]={465,328,487,342,501,350,508,352,509,355,508,359,495,367,
484,372,458,331};

int line[10]={458,331,476,341,490,348,498,352,507,359};
int line2[18]={92,346,81,353,80,356,78,362,77,371,77,386,79,391,83,398,83,406};
int line3[24]={97,389,136,388,208,387,261,386,305,387,349,387,373,387,
398,387,414,386,438,385,462,385,489,385};

int can[46]={521,287,521,277,523,272,526,267,531,264,542,263,556,262,
566,263,574,266,577,268,578,278,580,350,578,355,576,362,570,355,564,355,
554,353,546,353,538,355,530,359,527,363,525,361,523,349};
int can1[22]={525,268,527,263,536,260,546,259,558,259,567,261,571,263,
563,262,554,261,543,261,532,264};
int can2[42]={527,362,531,357,539,354,546,353,556,353,564,354,572,357,
576,360,576,365,571,369,566,371,557,373,554,373,551,373,548,375,544,375,
540,375,539,372,539,370,535,370,530,368};
int open[30]={540,368,535,367,531,366,531,364,535,360,542,357,550,356,
559,356,563,357,568,358,571,361,571,364,565,367,557,370,547,370};
int tip[24]={540,373,540,371,541,368,543,366,548,363,553,363,556,364,
557,367,553,371,552,373,548,375,544,375};
int last[12]={556,363,564,356,567,358,571,360,571,364,558,367};


int cloud[140]={70,0,68,11,69,16,71,21,72,25,73,31,76,35,80,39,80,44,80,49,81,59,
85,68,89,77,93,84,102,90,109,92,118,92,126,92,131,90,136,98,141,104,149,108,158,
111,164,122,176,129,186,131,199,132,211,130,219,128,224,127,231,123,234,129,241,
134,255,136,264,132,272,130,277,125,285,128,296,130,308,130,316,130,322,132,338,
136,357,134,368,131,382,124,391,115,398,110,406,103,414,108,418,111,425,111,437,
109,448,103,456,99,464,86,468,83,479,78,487,66,490,62,496,52,497,47,505,45,515,42,
522,38,530,29,535,19,535,10,530,0,70,0};

int land[44]={0,408,31,402,44,401,58,399,70,397,74,397,98,396,113,397,
123,398,458,401,483,402,506,402,531,401,551,401,576,402,590,404,609,
404,623,408,635,408,642,409,641,483,0,482};
int plant[46]={48,432,47,426,47,422,51,422,51,427,52,418,52,415,54,411,
55,415,57,420,57,422,59,419,59,415,62,415,62,420,62,425,68,422,70,425,
69,427,67,428,64,431,62,432,56,434};

setcolor(8);
setfillstyle(9,3);
bar(0,0,640,480);
rectangle(0,0,640,480);

setfillstyle(1,6);
fillpoly(22,land);

setfillstyle(1,10);
fillpoly(23,can);
fillpoly(22,plant);

setfillstyle(1,7);
fillpoly(11,can1);
fillpoly(21,can2);
drawpoly(15,open);
drawpoly(12,tip);

setfillstyle(1,8);
fillpoly(6,last);

setfillstyle(1,14);
bar(122,390,460,482);
rectangle(121,389,461,483);
fillpoly(37,top);
fillpoly(14,left);
fillpoly(9,right);
drawpoly(5,line);
drawpoly(9,line2);
drawpoly(12,line3);

setfillstyle(1,6);
fillpoly(76,bear1);
drawpoly(20,bear1hand);
drawpoly(22,bear1hand2);
fillpoly(10,bear1ear);

setfillstyle(1,15);
fillpoly(29,bear2);
fillpoly(7,bear3ear1);
fillpoly(9,bear3ear2);
fillpoly(7,bear3hand2);
fillpoly(67,bear3);
drawpoly(20,bear3hand);
fillpoly(70,cloud);
fillellipse(400,150,13,13);
fillellipse(370,180,10,10);
fillellipse(345,205,7,7);

setfillstyle(1,8);
fillpoly(13,bear2ear1);
fillpoly(7,bear2ear2);
fillpoly(31,bear2hand1);
fillpoly(21,bear2hand2);
drawpoly(10,bear2bump);
fillpoly(17,bear2patch1);
fillpoly(14,bear2patch2);
drawpoly(10,bear3bump);

setcolor(0);
drawpoly(5,bear1mouth);
drawpoly(5,bear2mouth);
fillpoly(13,bear1nose);
fillpoly(12,bear2nose);
fillpoly(11,bear3nose);
drawpoly(3,bear3mouth);
drawpoly(6,bear2eye1);
drawpoly(6,bear2eye2);
fillpoly(6,bear1eye1);
fillpoly(7,bear1eye2);
fillpoly(6,bear3eye1);
fillpoly(7,bear3eye2);
setcolor(BLACK);

settextstyle(2,0,10);
outtextxy(178,410,"Free Bears");


for(i=0; i<3; i++)
{
setfillstyle(SOLID_FILL,WHITE);
bar(124,6,482,80);
delay(300);
setcolor(8);
setbkcolor(WHITE);
settextstyle(0,0,5);
outtextxy(120,30,"Game Over");
delay(100);
bar(124,6,482,80);
delay(300);
outtextxy(120,30,"Game Over");
} //for blink	

closegraph();
startPage();
}

/***********************************************************************RANDOM******************************************/
void random(){
	
setcolor(BLACK);
	srand(time(0));
    int wordNum[36]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};	

random_shuffle(&wordNum[0],&wordNum[36]);
level_one(); //background 
level = 8;
for (unsigned i = 0; i < 36; i++)
 {

if (logoNumber>=36)
finish();

if(wordNum[i]==36)
{
logoNumber++;
logo_one();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("meralco");
}

if(wordNum[i]==1)
{
logoNumber++;
logo_two();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("swing");
}
if(wordNum[i]==2){
logoNumber++;
logo_three();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("seesaw");

}

if(wordNum[i]==3)
{
logoNumber++;
 logo_four();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("stapler"); }//if

if(wordNum[i]==4)
{
logoNumber++;
logo_5(); 
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("protractor"); }//if

if(wordNum[i]==5)
{
logoNumber++;
logo_6();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("marker"); 
} 

if(wordNum[i]==6)
{
logoNumber++;
logo_7();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("mazda"); } //if

if(wordNum[i]==7)
{
logoNumber++;
logo_8();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("hyundai"); }//if
if(wordNum[i]==8)
{
logoNumber++;
logo_9();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("mitsubishi"); }//if

if(wordNum[i]==9)
{
logoNumber++;
logo_10();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("honda"); }//if

if(wordNum[i]==10)
{
logoNumber++;
logo_11();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("burger"); } //if

if(wordNum[i]==11)
{
logoNumber++;
logo_12();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("taco"); }//if

if(wordNum[i]==12)
{
logoNumber++;
logo_13();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("chowking"); }//if

if(wordNum[i]==13)
{
logoNumber++;
logo_14();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
setcolor(BLACK);
setbkcolor(WHITE);
settextstyle(10,0,2);
outtextxy(352,330,"pizza");
playLogic("dominos"); }//if

if(wordNum[i]==14)
{
logoNumber++;
logo_15();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
setcolor(BLACK);
setbkcolor(WHITE);
settextstyle(10,0,2);
outtextxy(345,330,"donuts");
playLogic("dunkin"); }//if


if(wordNum[i]==15)
{
logoNumber++;
logo_16();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("skechers"); } //if
if(wordNum[i]==16)
{
logoNumber++;
logo_17();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("adidas"); }//if
if(wordNum[i]==17)
{
logoNumber++;
logo_18();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("fila");}//if
if(wordNum[i]==18)
{
logoNumber++;
logo_19();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("puma");}//if
if(wordNum[i]==19)
{
logoNumber++;
logo_20();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("merrell");}//if
if(wordNum[i]==20)
{
logoNumber++;
logo_21();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("mizuno");}//if

if(wordNum[i]==21)
{
logoNumber++;
logo_22();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("knorr");}

if(wordNum[i]==22)
{
logoNumber++;
logo_23();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("maggi");}

if(wordNum[i]==23)
{
logoNumber++;
logo_24();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("jollibee");}

if(wordNum[i]==24)
{
logoNumber++;
logo_25();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("gatorade");}

if(wordNum[i]==25)
{
logoNumber++;
logo_26();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("kelloggs");}

if(wordNum[i]==26)
{
logoNumber++;
logo_27();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("greenwich");}

if(wordNum[i]==27)
{
logoNumber++;
logo_28();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("heinz");}

if(wordNum[i]==28)
{
logoNumber++;
logo_29();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("philippines");}

if(wordNum[i]==29)
{
logoNumber++;
logo_30();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("france");}

if(wordNum[i]==30)
{
logoNumber++;
logo_31();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("germany");}

if(wordNum[i]==31)
{
logoNumber++;
logo_32();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("indonesia");}

if(wordNum[i]==32)
{
logoNumber++;
logo_33();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("italy");}

if(wordNum[i]==33)
{
logoNumber++;
logo_34();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("sweden");}

if(wordNum[i]==34)
{
logoNumber++;
logo_35();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("kuwait");}

if(wordNum[i]==35)
{
logoNumber++;
logo_36();
//borders
setcolor(BLACK);
setfillstyle(SOLID_FILL,RED);
fillpoly(4, logonum);
fillpoly(4, levelnum);
//texts
settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);	
outtextxy(6,15, "RANDOM");
outtextxy(6,38, "ROUND");
settextstyle(2,0,8);
outtextxy(280,8," of 36");
sprintf(lnArr, "%d", logoNumber);
outtextxy(252, 8, lnArr);
playLogic("kenya");
}


//finish();

}//for
}//random

/************************************************************************LEVEL MODE***************************************************/

void levelMode(){

setcolor(BLACK); //outline color

//setcolor(BLACK);


if(level==0){

map();
level_one(); //background 1
logo_one();
playLogic("meralco");
finish();
level++;
map();
//end of level one 
}//if level

	srand(time(0));
    int wordNum[8]={1,2,3,4,5,6,7,8};

if(level==1){
level_two();
    random_shuffle(&wordNum[0],&wordNum[2]);
for (unsigned i = 0; i < 2; i++)
 {
if(wordNum[i]==1)
{
logoNumber++;
logo_two();
playLogic("swing");

}
if(wordNum[i]==2){
logoNumber++;
logo_three();
playLogic("seesaw");
} }//for
finish();
level++;
map();
logoNumber=0;
//end of level two
}//if level


if(level==2){
level_three();

random_shuffle(&wordNum[0],&wordNum[3]);

for (unsigned i = 0; i < 3; i++)
 {
if(wordNum[i]==1)
{
logoNumber++;
 logo_four();
playLogic("stapler"); }//if

if(wordNum[i]==2)
{
logoNumber++;
logo_5(); 
playLogic("protractor"); }//if

if(wordNum[i]==3)
{
logoNumber++;
logo_6();
playLogic("marker"); 
} }//for
finish();
level++;
map();
logoNumber=0;
//end of level three
}//if level


if(level==3){
level_four();

random_shuffle(&wordNum[0],&wordNum[4]);

for (unsigned i = 0; i < 4; i++)
 {
if(wordNum[i]==1)
{
logoNumber++;
logo_7();
playLogic("mazda"); } //if

if(wordNum[i]==2)
{
logoNumber++;
logo_8();
playLogic("hyundai"); }//if
if(wordNum[i]==3)
{
logoNumber++;
logo_9();
playLogic("mitsubishi"); }//if

if(wordNum[i]==4)
{
logoNumber++;
logo_10();
playLogic("honda"); }//if
}//for
finish();
level++;
map();
logoNumber=0;
}//if level
//end of level 4


if(level==4){
level_five();
random_shuffle(&wordNum[0],&wordNum[5]);

for (unsigned i = 0; i < 5; i++)
 {
if(wordNum[i]==1)
{
logoNumber++;
logo_11();
playLogic("burger"); } //if

if(wordNum[i]==2)
{
logoNumber++;
logo_12();
playLogic("taco"); }//if

if(wordNum[i]==3)
{
logoNumber++;
logo_13();
playLogic("chowking"); }//if

if(wordNum[i]==4)
{
logoNumber++;
logo_14();
setcolor(BLACK);
setbkcolor(WHITE);
settextstyle(10,0,2);
outtextxy(352,330,"pizza");
playLogic("dominos"); }//if

if(wordNum[i]==5)
{
logoNumber++;
logo_15();
setcolor(BLACK);
setbkcolor(WHITE);
settextstyle(10,0,2);
outtextxy(345,330,"donuts");
playLogic("dunkin"); }//if

setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);

}//for
finish();
level++;
map();
logoNumber=0;
}//if level
//end of level 5


if(level==5){
level_six();

random_shuffle(&wordNum[0],&wordNum[6]);

for (unsigned i = 0; i < 6; i++)
 {
if(wordNum[i]==1)
{
logoNumber++;
logo_16();
playLogic("skechers"); } //if
if(wordNum[i]==2)
{
logoNumber++;
logo_17();
playLogic("adidas"); }//if
if(wordNum[i]==3)
{
logoNumber++;
logo_18();
playLogic("fila");}//if
if(wordNum[i]==4)
{
logoNumber++;
logo_19();
playLogic("puma");}//if
if(wordNum[i]==5)
{
logoNumber++;
logo_20();
playLogic("merrell");}//if
if(wordNum[i]==6)
{
logoNumber++;
logo_21();
playLogic("mizuno");}//if
}//for
finish();
level++;
map();
logoNumber=0;
}//if level
//end of level 6 

if(level==6){
level_seven();

random_shuffle(&wordNum[0],&wordNum[7]);

for (unsigned i = 0; i < 7; i++)
 {
if(wordNum[i]==1)
{
logoNumber++;
logo_22();
playLogic("knorr");}

if(wordNum[i]==2)
{
logoNumber++;
logo_23();
playLogic("maggi");}

if(wordNum[i]==3)
{
logoNumber++;
logo_24();
playLogic("jollibee");}

if(wordNum[i]==4)
{
logoNumber++;
logo_25();
playLogic("gatorade");}

if(wordNum[i]==5)
{
logoNumber++;
logo_26();
playLogic("kelloggs");}

if(wordNum[i]==6)
{
logoNumber++;
logo_27();
playLogic("greenwich");}

if(wordNum[i]==7)
{
logoNumber++;
logo_28();
playLogic("heinz");}

}//for
finish();
level++;
map();
logoNumber=0;
}//if level
//end of level 7


if(level==7){
level_eight();

random_shuffle(&wordNum[0],&wordNum[8]);

for (unsigned i = 0; i < 8; i++)
 {
if(wordNum[i]==1)
{
logoNumber++;
logo_29();
playLogic("philippines");}

if(wordNum[i]==2)
{
logoNumber++;
logo_30();
playLogic("france");}

if(wordNum[i]==3)
{
logoNumber++;
logo_31();
playLogic("germany");}

if(wordNum[i]==4)
{
logoNumber++;
logo_32();
playLogic("indonesia");}

if(wordNum[i]==5)
{
logoNumber++;
logo_33();
playLogic("italy");}

if(wordNum[i]==6)
{
logoNumber++;
logo_34();
playLogic("sweden");}

if(wordNum[i]==7)
{
logoNumber++;
logo_35();
playLogic("kuwait");}

if(wordNum[i]==8)
{
logoNumber++;
logo_36();
playLogic("kenya");}
}//for
finish();
level=0;
logoNumber=0;
}//if level 

getch();
closegraph();
restorecrtmode();
} //levelMode

/***********************************************************************HOW TO***************************/

void howTo(){
	
//navigations
setlinestyle(SOLID_LINE, 0, 1);
setcolor(BLACK);
const int SPACE = 32;
char response, responseArr[100];
char *valid;

setfillstyle(SOLID_FILL, WHITE);
bar(8,27,635,477);


settextstyle(2,0,7);
setbkcolor(WHITE);

outtextxy(280,55,"Instructions");
outtextxy(20,80,"1) Try to guess the logo/picture that appears on the screen.");
outtextxy(20,100,"2) Type the letter to see if you are right. Letters are repeated if it is");
outtextxy(20,120,"already guessed. (As long as you guess the letter correctly, your life");
outtextxy(20,140,"won't be deducted).");
outtextxy(20,160,"3) There are only 3 misses allowed. If you're out of lives,");
outtextxy(20,190,"the game will be over and you'll have to start again.");
outtextxy(20,220,"4) How about being Stuck? You can use the hint button ('Tab' to use Hint)");
outtextxy(20,240,"to reveal a letter.");
outtextxy(20,260,"5) You need to answer the picture/logo correctly to get to the next level.");
outtextxy(20,280,"(Clicking the 'ESC' will get you back to menu and once you play");
outtextxy(25,300," again, it starts back at the first sub level shuffled.)");
outtextxy(20,320,"6) Play fair and Have fun!");

settextstyle(2,0,5);
	setcolor(WHITE);
	setbkcolor(RED);
outtextxy(440,455, "Press ESC to go back home");

balik:
setfillstyle(SOLID_FILL, WHITE);
bar(167,444,469,458);
	
response = getch();
sprintf(responseArr, "%c", response);
valid = strstr(validLetters, responseArr);
if (GetAsyncKeyState(VK_ESCAPE)){
			closegraph(); 
			startPage();}
else {
	settextstyle(2,0,5);
		outtextxy(180, 445, "WRONG KEY! PRESS ANY KEY TO ENTER AGAIN");
		getch();
		goto balik;
}//else
}



/*********************************START**********************************************************************/
void startPage()
{

int gd=DETECT, gm;
initgraph(&gd, &gm, "c:\\turboc3\\bgi");


SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, NULL);
//random();
/************************START PAGE*****************/
//background
	
	balik:
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, CYAN);
	bar(9,19,634,476);

	
	int mt[48]={6,262,16,260,25,261,36,263,50,267,63,269,83,272,100,271,118,269,148,260,
				172,257,194,251,214,249,237,245,263,244,295,241,324,243,345,244,390,250,403,253,
				432,260,447,264,536,313,7,312}; //mt= mountain (green)
	int grassA[52]={11,275,15,272,18,269,23,270,19,274,24,277,30,278,32,282,36,283,36,277,
					38,287,41,289,44,290,50,290,51,298,55,303,59,306,64,309,65,306,70,303,
					66,313,78,313,70,318,77,319,85,322,11,327}; //left
	int grassB[100]={11,323,25,323,42,323,64,323,90,319,104,318,125,317,137,321,146,323,150,323,
					151,320,151,329,153,329,157,329,154,332,158,332,160,338,156,342,152,340,150,343,
					144,348,146,340,143,338,138,337,122,335,118,337,108,340,102,338,100,341,105,346,
					93,340,87,342,80,343,67,341,63,341,67,347,61,348,57,340,54,340,51,343,
					42,348,46,338,40,339,26,339,32,343,34,347,24,345,18,340,12,343,9,346};
	int landA[28]={10,331,154,332,160,342,165,353,171,367,186,367,194,366,203,366,214,369,218,369,
					378,351,628,344,630,474,5,475};
	int grassC[154]={215,367,210,371,206,367,206,359,208,355,214,353,213,346,213,343,211,338,217,335,
					220,331,219,327,221,323,226,323,230,319,234,318,237,322,242,324,242,311,245,308,
					245,324,245,333,253,319,258,314,260,307,255,324,253,331,254,336,258,328,258,325,
					260,335,263,342,263,333,265,341,269,343,269,335,270,347,277,345,275,331,280,324,
					283,339,290,329,292,326,302,325,306,326,302,319,313,316,310,332,314,332,318,333,
					322,342,330,343,337,337,341,343,344,335,342,324,348,330,349,320,344,313,352,330,
					352,311,352,302,355,324,358,318,365,311,360,324,363,319,367,326,370,331,374,333,
					380,329,378,338,378,343,387,327,377,347,379,355,381,359};
	int grassD[88]={219,368,217,363,217,355,218,350,224,350,225,343,230,341,231,336,233,331,238,331,
					244,343,250,343,257,347,257,350,265,352,269,352,278,353,282,352,282,346,286,346,
					289,347,287,338,295,339,306,332,312,343,321,343,326,350,318,351,333,355,338,355,
					338,359,340,368,345,369,347,372,351,377,322,375,309,376,300,377,282,377,285,370,
					278,372,270,377,273,367,273,363};
	int grassE[56]={629,327,435,327,438,324,438,320,432,326,428,312,427,329,422,322,424,328,402,328,
					393,332,387,338,381,339,384,343,387,350,396,343,397,347,409,340,408,347,439,339,
					439,343,441,349,450,343,462,340,475,342,606,347,606,342,633,342};
	int landB[48] ={632,335,395,338,392,338,382,343,378,351,374,361,374,365,369,371,366,375,362,381,
					358,393,355,400,352,406,359,410,367,414,382,407,390,407,392,406,403,404,424,408,
					607,413,617,412,622,412,631,423};
	int grassF[70]={230,295,222,296,218,298,214,299,211,306,218,304,221,311,226,299,231,302,234,303,
					238,301,242,301,244,302,246,301,249,299,250,304,255,303,262,303,267,299,268,307,
					278,299,283,300,290,304,298,306,306,305,310,311,310,303,318,307,314,303,323,307,
					319,303,312,297,308,295,302,295,292,294};
	int landC[40]= {313,298,227,299,214,302,210,307,206,312,205,315,202,319,202,325,212,327,222,325,
					228,323,242,326,255,327,264,329,281,328,298,329,330,327,333,323,326,313,318,307 };
	int grassG[12]={634,299,616,283,611,291,604,295,598,268,631,268};

	setfillstyle(SOLID_FILL, LIGHTGREEN);
	fillpoly(24, mt);
	setfillstyle(SOLID_FILL,BLUE);
	bar(12,312,586,369);
	setfillstyle(SOLID_FILL, BROWN);
	fillpoly(14, landA);
	fillpoly(20,  landC);
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	fillpoly(26, grassA);
	fillpoly(50, grassB);
	fillpoly(77,grassC);
	fillpoly(44,grassD);
	fillpoly(28,grassE);

	
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	fillpoly(35, grassF);
	fillpoly(6, grassG);

	setfillstyle(SOLID_FILL, BROWN);
	fillpoly(24,  landB);
	bar(629,282,571,331);
	

//title

	int t[50]= {37,119,34,121,32,122,32,124,32,128,33,130,35,132,38,132,41,132,42,134,
				42,165,43,169,45,171,52,171,53,169,55,167,55,135,55,133,56,131,59,131,
				62,131,65,129,66,125,64,122,61,119};
	int r[58]= {74,119,72,121,70,123,69,126,69,165,70,169,72,170,77,171,81,169,82,167,
				82,157,82,155,84,155,94,171,96,171,99,171,104,168,104,165,104,163,96,150,
				98,147,100,144,101,142,102,137,101,133,100,130,97,126,93,122,89,119};
	int inR[16]={82,133,82,140,83,142,85,142,88,140,87,136,87,134,85,133};
	int a[44]={128,119,125,121,124,124,109,161,108,165,108,168,110,170,114,172,117,171,119,170,
			   124,160,137,159,139,163,142,169,145,170,148,171,151,170,154,168,154,163,137,123,
			   135,121,133,119};
	int inA[6]={131,141,129,146,133,146};
	int v[40]={157,121,155,120,151,119,148,120,146,122,146,126,159,165,160,169,163,170,169,171,
			   171,169,186,126,185,123,182,120,179,119,175,121,174,123,172,129,167,147,158,123};
	int e[62]={218,131,220,131,221,129,223,127,223,125,221,121,218,119,197,119,195,120,193,122,
			   193,124,193,165,194,168,196,169,218,170,221,169,223,167,222,161,220,158,207,158,
			   206,152,212,151,214,148,216,146,215,143,216,141,213,138,211,137,207,138,206,132,
			   216,132};
	int l1[38]={241,124,240,122,239,120,237,119,233,120,231,120,230,122,229,126,228,164,228,166,
			   229,169,231,171,254,172,257,168,258,165,256,161,254,158,242,159,242,126};
	int l2[32]={275,124,273,122,271,120,267,120,264,121,262,124,262,163,262,167,264,169,265,171,
				287,171,290,168,291,166,290,162,288,159,275,158};
	int  i[24]={310,122,308,122,305,119,302,118,300,119,297,122,297,124,297,166,299,169,301,170,
			    306,170,309,167};
	int  n[46]={328,121,326,120,324,119,320,120,318,124,318,166,319,170,322,171,325,171,330,168,
				330,149,343,170,346,171,350,172,353,170,355,167,355,125,353,121,349,120,345,121,
				343,124,343,142,330,123};
	int g[120]={408,128,406,126,403,124,400,121,396,119,392,119,387,119,381,119,375,122,370,126,
				367,130,364,137,362,144,364,154,369,161,372,165,376,168,382,170,387,170,395,170,
				399,168,404,166,407,163,410,160,414,153,414,150,414,146,411,143,410,141,390,142,
				387,145,386,147,387,151,390,153,397,154,394,156,392,158,388,158,384,157,381,155,
				378,153,376,149,376,144,376,141,377,139,379,137,380,135,382,134,384,133,386,132,
				390,131,392,132,395,133,396,135,398,136,401,136,404,137,406,135,408,134,409,132};
	
	
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(25,t);
	fillpoly(29,r);
	fillpoly(22,a);
	fillpoly(20,v);
	fillpoly(31,e);
	fillpoly(19,l1);
	fillpoly(16,l2);
	fillpoly(12,i);
	fillpoly(23,n);
	fillpoly(60,g);
	//letter holes
	setfillstyle(SOLID_FILL, CYAN);
	fillpoly(8,inR);
	fillpoly(3,inA);
	
	//BEARS
	
		int B[78]={59,178,56,179,54,181,52,183,51,186,51,189,50,261,52,263,54,265,57,267,
			   85,267,89,267,94,265,99,262,105,259,108,255,111,252,112,249,113,245,113,240,
			   113,234,112,230,110,225,106,220,104,217,101,216,103,214,105,211,106,208,106,204,
			   107,199,106,195,105,192,103,187,100,184,96,181,92,180,86,178,76,178};
	int inB1[12]={74,203,73,199,82,199,84,200,84,202,82,203}; 
	int inB2[22]={73,229,73,243,74,245,84,245,88,244,89,242,91,239,91,236,89,232,86,230,84,229};
	int E[76]={123,178,120,179,118,181,116,184,115,187,115,259,117,263,119,266,122,267,159,268,
			   163,265,165,262,167,259,167,254,166,250,162,246,158,245,138,245,138,233,145,233,
			   148,232,151,231,154,227,154,222,153,217,151,213,148,212,138,211,138,200,159,200,
			   163,198,165,196,167,193,167,188,167,185,165,182,162,179,159,178};
	int A[54]={226,180,223,179,220,177,216,177,213,178,210,180,207,181,178,253,178,257,179,261,
			   180,264,183,265,186,267,190,267,194,266,197,264,206,246,228,245,235,263,238,265,
			   242,267,246,267,249,266,253,264,256,260,256,254,227,183};
	int R[78]={276,177,274,178,271,181,268,184,268,187,268,258,270,262,272,265,275,267,281,267,
			   284,266,290,262,290,260,290,238,292,239,294,239,309,264,313,267,316,267,319,267,
			   322,266,326,263,327,259,327,255,327,251,313,230,316,226,319,223,321,220,323,216,
			   323,212,324,208,323,202,322,197,319,193,315,188,311,183,306,181,300,177};
	int S[168]={366,198,369,198,373,199,376,200,378,202,381,202,385,202,388,201,390,199,393,196,
			   393,193,393,191,391,187,388,185,385,181,381,179,375,177,371,177,366,177,361,177,
			   355,178,349,182,345,185,342,190,339,196,339,200,339,205,339,210,342,213,345,217,
			   348,219,351,221,354,222,358,225,361,226,366,227,368,229,371,231,373,234,374,239,
			   372,241,370,242,367,244,363,244,358,241,355,239,351,237,348,236,343,237,338,239,
			   336,242,335,247,335,252,338,257,343,260,350,265,355,265,359,267,366,266,372,266,
			   377,265,381,263,384,261,388,258,390,255,391,253,393,250,395,247,396,242,396,238,
			   396,233,395,229,392,224,389,220,384,216,381,213,377,212,374,210,370,210,367,208,
			   364,206,362,204,362,201,363,199};
	int inR1[16]={291,199,290,214,294,215,297,214,300,211,301,208,301,204,297,199};
	int inA1[6]={214,226,217,217,220,226};
	setfillstyle(SOLID_FILL, RED);
	fillpoly(39,B);
	fillpoly(38, E);
	fillpoly(27, A);
	fillpoly(39, R);
	fillpoly(84, S);
	setfillstyle(SOLID_FILL,CYAN);
	fillpoly(6, inB1);
	fillpoly(11, inB2);
	fillpoly(3, inA1);
	fillpoly(8, inR1);
	
	/*settextstyle(2,0,8);
	setcolor(WHITE);
	setbkcolor(BROWN);	
	outtextxy(30,420, "press any key to continue...");*/


setcolor(BLACK);

	int grizz[116]={489,139,488,137,485,135,481,135,474,139,473,142,465,141,457,141,449,144,442,148,
   				   436,155,431,164,426,165,417,168,412,171,407,177,405,180,405,186,406,194,412,203,
				   419,209,428,213,438,218,449,222,458,223,467,226,486,227,488,235,489,242,492,249,
				   498,256,503,256,513,252,517,244,519,230,533,230,542,230,557,230,565,227,565,237,
				   569,244,576,251,586,249,594,240,598,227,600,220,608,208,613,201,616,190,618,175,
				   615,165,608,151,598,148,587,143,571,138,553,134,532,133,511,134};
   int grizzT[16]={607,151,611,150,615,146,619,148,620,153,616,160,615,164,610,159};
   
	int grizzE[14]={ 454,142,455,138,459,133,461,134,463,137,463,140,459,141};
	int grizzF1[16]={493,229,480,227,469,226,469,231,472,243,475,251,492,251,496,249};
	int grizzF2[12]={547,230,547,237,549,241,554,247,573,247,572,225};
	
//ib = icebear
	int icebear[124]={488,341,486,338,482,336,478,338,476,341,473,343,468,342,462,342,453,344,446,347,
					  439,352,435,356,432,361,431,367,426,368,420,370,415,374,411,377,409,383,409,388,
					  414,397,425,407,441,415,455,419,461,420,464,430,466,439,471,447,477,448,479,447,
					  483,444,486,447,489,452,493,452,497,452,506,442,508,437,512,424,521,425,531,425,
					  552,427,573,424,576,426,580,436,588,445,593,447,594,449,600,446,606,437,606,425,
					  606,413,605,410,610,404,615,392,616,378,616,364,611,354,603,347,597,343,584,337,
					  559,337,522,338};
	int icebearN[18]={428,383,424,383,420,382,417,380,420,377,424,377,429,377,434,380,434,382};
	int ibEye1[12]=	 {455,376,453,375,452,373,454,371,456,371,458,374};
	int ibEye2[10]=  {434,372,433,369,435,367,437,369,436,372};
	int ibLip[8]=	 {441,395,444,394,448,394,450,395};
	int ibEar1[14]=  {450,347,450,343,452,340,455,338,458,337,461,340,461,343};
	int ibTail[12]=  {610,353,612,352,615,351,618,354,618,366,615,368};
	int ibFL1 [8]=  {475,409,477,421,480,433,486,446};
	int ibFL2 [6]=  {476,421,468,421,460,421};
	int ibFL3[24]=  {510,409,512,418,511,425,519,425,531,427,562,427,574,423,576,423,574,417,573,409,
					 572,404,572,401};
	int ibFL4[18]=  {582,421,568,425,560,427,562,433,564,444,570,449,576,449,582,443,584,436};
	int pandaF3[16]={476,325,474,331,473,339,475,342,475,349,499,349,507,346,496,325};	
		
	//panda Foot 3 detail	
		setfillstyle(SOLID_FILL, DARKGRAY);
		fillpoly(8, pandaF3);
		bar(563,318,587,352); //foot 4
		
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly (7,ibEar1);
	fillpoly(9, ibFL4);
	fillpoly (6,ibTail);
	fillpoly(62, icebear);
	
	//icebear face
	setfillstyle(SOLID_FILL, BLACK);
	fillpoly(9, icebearN);
	fillpoly (6,ibEye1);
	fillpoly (5,ibEye2);
	drawpoly(4, ibLip);
	drawpoly(4, ibFL1); //FL = Foot Line
	drawpoly(3, ibFL2);
	drawpoly(12, ibFL3);
	
	
	
	setfillstyle(SOLID_FILL, BROWN);
	//grizz foot 1 and 2
	fillpoly(8,grizzF1);
	fillpoly(6,grizzF2);
	
//panda
	int panda[152]={491,247,487,246,484,246,482,248,480,251,476,250,470,250,462,252,454,254,448,256,
					444,258,439,261,435,265,433,268,431,271,430,274,426,274,422,278,418,280,415,286,
					414,291,416,297,418,303,421,307,425,311,431,315,437,319,445,322,456,325,463,326,
					469,328,480,331,486,330,492,331,494,335,495,341,498,345,502,349,507,352,511,352,
					518,350,522,345,523,339,523,332,527,332,533,333,545,335,556,335,565,334,568,333,
					570,336,572,343,575,348,580,351,586,353,593,350,598,342,599,334,600,327,601,321,
					605,319,609,309,610,299,611,292,611,285,610,276,606,268,603,261,599,257,592,252,
					587,248,569,243,555,243,548,243,539,242,520,243};
	int pandaF1[46]={498,260,497,271,496,277,494,289,493,307,493,316,493,328,495,339,500,346,506,350,
					 512,349,515,349,519,347,523,337,523,326,524,313,529,283,531,270,536,252,543,243,
					 524,243,505,245,499,245};
	int pandaF2[42]={601,320,599,332,595,339,594,346,589,350,585,353,578,351,574,345,570,338,566,318,
					 564,297,567,276,572,257,575,246,584,246,592,251,601,260,608,272,611,287,610,302,
					 606,314};

	int pandaE1[28]={465,289,459,290,454,289,451,285,447,279,448,272,450,268,453,265,456,264,460,266,
					 463,268,467,272,470,279,470,285};
	int pandaE2[22]={430,273,427,274,429,275,433,278,436,277,441,275,443,271,443,266,440,261,434,264,
					 431,270};
	int panEar1[14]={464,250,464,247,462,244,458,246,455,249,455,251,455,254};
	int panEar2[22]={489,246,487,244,484,245,481,249,481,252,483,254,486,255,490,254,492,253,495,250,
					 494,244};

	int panLip[12]=   {432,299,435,301,439,301,443,300,447,298,448,296};
	int panNose[18]=  {434,285,430,286,426,285,424,282,424,280,427,279,430,279,433,280,435,282};
	int panEye1[12]=   {456,273,455,276,456,279,458,279,460,276,459,273};
	int panEye2[10]=  {439,269,436,269,435,272,438,275,439,273};
	
	setfillstyle(SOLID_FILL, DARKGRAY);
	fillpoly(7, panEar1);

	setfillstyle(SOLID_FILL, WHITE);
		fillpoly(76, panda);
		

	//panda details
		setfillstyle(SOLID_FILL, DARKGRAY);
	
		fillpoly(23, pandaF1);
		fillpoly(21, pandaF2);
		fillpoly(14, pandaE1);
		fillpoly(11, pandaE2);
		fillpoly(11, panEar2);
		drawpoly(6, panLip);
		setfillstyle(SOLID_FILL, BLACK);
		fillpoly(9, panNose);
		fillpoly(6, panEye1);
		fillpoly(5, panEye2);
		
	//grizz
	int grizzEye1[12]= {459,165,456,166,455,168,456,171,460,171,460,167};
	int grizzEye2[10]= {436,163,434,163,432,165,434,168,438,167};
	int grizzNose[18]= {431,172,428,172,423,172,422,175,424,177,427,177,432,177,434,175,433,173};
	int grizzM[32]={426,186,424,186,423,188,424,191,428,192,433,194,439,196,445,193,450,191,453,186,
					455,182,452,180,448,179,443,182,440,184,435,186};
	int grizzTeeth[30]={426,186,427,188,429,188,431,187,433,188,435,188,437,187,438,185,440,186,442,187,
					445,186,446,182,442,183,438,183,430,185};

	setfillstyle(SOLID_FILL, BROWN);
	fillpoly(8, grizzT); //tail
	fillpoly(58, grizz);
	fillpoly(7, grizzE); //ear
	
	
	setfillstyle(SOLID_FILL, BLACK);
	fillpoly(6, grizzEye1); 
	fillpoly(5,grizzEye2);
	fillpoly(9,grizzNose);
	
	setfillstyle(SOLID_FILL, RED);
	fillpoly(16, grizzM); 
	
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(15, grizzTeeth); 
	
	
	char choice;
	//menu
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, RED);
	bar(129,289,308,319);
	rectangle(129,289,308,319);
	bar(132,325,308,351);
	rectangle(132,325,308,351);
	bar(134,358,310,383);
	rectangle(134,358,310,383);
	bar(134,388,312,412);
	rectangle(134,388,312,412);
	
	

	setcolor(WHITE);
	setbkcolor(RED);	
	settextstyle(2,0,7);
	outtextxy(155,294,"[A] LEVEL MODE" );
	outtextxy(155,325, "[B]   RANDOM");
	outtextxy(155,360, "[C] HOW TO PLAY");
	outtextxy(155,390, "[D]   EXIT");
	

	setfillstyle(SOLID_FILL, RED);
	bar(630,0,640,480);
	bar(1,0,10,480);
	bar(0,1,640,35);
	bar(0,473,640,480);
	choice = toupper(getch());
	

	if(choice=='A')
	levelMode();
	else if(choice=='B'){
	miss=3;
	hintNum=5;
	logoNumber=0;
	random();
	}//if
	else if(choice=='C')
	howTo();
	else if(choice=='D')
	closegraph();
	else{
			settextstyle(2,0,5);
		outtextxy(180, 445, "WRONG KEY! PRESS ANY KEY TO ENTER AGAIN");
		getch();
		goto balik;
	}

/*******************END OF START PAGE***********************/	
}


main() {

	startPage();

	return 0;
}

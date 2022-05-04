#include<stdio.h>


void PrintMaze(int r,int c,char arr[r][c]){
int i,j;
for(i=0;i<r;i++){
for(j=0;j<c;j++){
printf("%c",arr[i][j]);
}
printf("\n");
}
printf("\n");
}//the end of print func


int GameOver(int r,int c,char array[r][c]){
int i,j,check=0;
for(i=1;i<r;i++){
for(j=1;j<c-1;j++){if(array[i][j]!=' '){check++;}}}
if(check==0)
return 1;
else
return 0;
}//the end of game over func



int DestroyBricks(int r,int c,char array[r][c],int posX,int posY){
int i,j,check=0;
char color=array[posY][posX];

for(i=-1;i<2;i++){
for(j=-1;j<2;j++){

if(array[posY+i][posX+j]==color){check++;}

}}


if(check>2){
for(i=-1;i<2;i++){
for(j=-1;j<2;j++){
if(array[posY+i][posX+j]==color){array[posY+i][posX+j]=' ';}
}}

if(check==3)
return 30;
else if(check==4)
return 40;
else if(check>4)
return 100;

}

return 0;

}//end of destroy function





int main(){

int point=0;
int row,column;
scanf("%d%d",&row,&column);
int r,c;
r=column;
c=row;
char maze[r][c];

//***************maze content**************************
int i,j;

 char temp[c],buff;
for(i=0;i<r;i++){
for(j=0;j<c;j++){
if(j==0){maze[i][j]='|';}
else if(j==c-1){maze[i][j]='|';}
else if(i==0){maze[i][j]='~';}
else{maze[i][j]=' ';}

}
}
for(i=1;i<r;i++){

for(j=0;j<c;j++){temp[j]='\n';}

scanf("%c",&buff);
scanf("%[^\n]",temp);
if(temp[0]=='e')
break;
j=0;
for(;temp[j]!='\00';j++){maze[i][j+1]=temp[j];}
}
//********************x,y cordinate for start position***************
int locX,locY,tempLocX,templocY;
scanf("%d%d",&locX,&locY);
maze[locY][locX]='_';
PrintMaze(column,row,maze);
tempLocX=locX;
templocY=locY;

//*********************start-game******************
double D_i,D_j;
char color;
double x,y;

double posX1,posY1,posX2,posY2;
int inX,inY,no;
int checkWall=0;
while(1){
if(GameOver(r,c,maze)){break;}

if(checkWall==0){
locX=tempLocX;
locY=templocY;

scanf(" %c",&color);
if(color=='q'){break;}
scanf("%lf%lf",&x,&y);
}



if(x==0){
i=locY;
while(1){
if(maze[i-1][locX]!=' '){
maze[i][locX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,locX,i);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;

}
i--;
}

}//x==0*************************

else if(x==y){
for(j=locX,i=locY;;i--,j--)
{
if(maze[i-1][j-1]!=' '){
if(maze[i-1][j-1]=='|'&&maze[i-1][j]==' '){checkWall++;x=(x*-1);locX=j,locY=i;break;}
else{checkWall=0;
maze[i][j]=color;
no=point;
point=point+DestroyBricks(r,c,maze,j,i);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}
}//for

}//x==y


else if(-1*x==y){
for(j=locX,i=locY;;i--,j++)
{
if(maze[i-1][j+1]!=' '){
if(maze[i-1][j+1]=='|'&&maze[i-1][j]==' '){checkWall++;x=(x*-1);locX=j+1,locY=i;break;}
else{checkWall=0;
maze[i][j]=color;
no=point;
point=point+DestroyBricks(r,c,maze,j,i);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}
}//for

}//-x==y




else if(x<0){


D_i=D_j=1.0;

if((-1*y)>(-1*x)){
while(1){

if(((x/y)*D_i)>=D_j){


posY2=(locY-((y/x)*D_j));
posX2=locX-(1.0*D_j);
inX=posX2;
inY=posY2;






if(posY2==inY){
if(maze[inY-1][inX-1]!=' '){
if(maze[inY-1][inX-1]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posY2==inY){
if(maze[inY][inX-1]!=' '){
if(maze[inY][inX-1]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posY2!=inY){
if(maze[inY][inX-1]!=' '){
if(maze[inY][inX-1]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

++D_j;

}//x cordinate check


posX1=(locX-((x/y)*D_i));
posY1=locY-(1.0*D_i);
inX=posX1;
inY=posY1;




if(posX1==inX){
if(maze[inY-1][inX-1]!=' '){
if(maze[inY-1][inX-1]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posX1==inX){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posX1!=inX){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);

if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}


++D_i;



}//while

}//if -1*y>-1*x




else if((-1*x)>(-1*y)){
while(1){

if(((y/x)*D_j)>=D_i){

posX1=(locX-((x/y)*D_i));
posY1=locY-(1.0*D_i);
inX=posX1;
inY=posY1;



if(posX1==inX){
if(maze[inY-1][inX-1]!=' '){
if(maze[inY-1][inX-1]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posX1==inX){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posX1!=inX){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}


++D_i;


}//y cordinate check


posY2=(locY-((y/x)*D_j));
posX2=locX-(1.0*D_j);
inX=posX2;
inY=posY2;





if(posY2==inY){
if(maze[inY-1][inX-1]!=' '){
if(maze[inY-1][inX-1]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posY2==inY){
if(maze[inY][inX-1]!=' '){
if(maze[inY][inX-1]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posY2!=inY){
if(maze[inY][inX-1]!=' '){
if(maze[inY][inX-1]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

++D_j;


}//while

}//if -1*x>-1*y



}//x<0*********************************








else if(x>0){



D_i=D_j=1.0;

if((-1*y)>x){
while(1){

if(((x/y)*D_i*-1)>=D_j){


posY2=(locY+((y/x)*D_j));
posX2=locX+1+(1.0*D_j);
inX=posX2;
inY=posY2;





if(posY2==inY){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posY2==inY){
if(maze[inY][inX]!=' '){
if(maze[inY][inX]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posY2!=inY){
if(maze[inY][inX]!=' '){
if(maze[inY][inX]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

++D_j;

}//x cordinate check


posX1=(locX+1-((x/y)*D_i));
posY1=locY-(1.0*D_i);
inX=posX1;
inY=posY1;



if(posX1==inX){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posX1==inX){
if(maze[inY-1][inX-1]!=' '){
if(maze[inY-1][inX-1]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posX1!=inX){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX-1]!=' '){inX--;}

if(maze[inY-1][inX]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}


++D_i;



}//while

}//if -1*y>-1*x




else if(x>(-1*y)){
while(1){

if(((y/x)*D_j*-1)>=D_i){

posX1=(locX+1-((x/y)*D_i));
posY1=locY-(1.0*D_i);
inX=posX1;
inY=posY1;

if(posX1==inX){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posX1==inX){
if(maze[inY-1][inX-1]!=' '){

if(maze[inY-1][inX-1]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posX1!=inX){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX-1]!=' '){inX--;}
if(maze[inY-1][inX]=='|'&&maze[inY-1][inX]==' '){checkWall++;x=(x*-1);locX=posX1,locY=posY1;break;}
else{checkWall=0;
maze[inY][inX]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}


++D_i;


}//y cordinate check





posY2=(locY+((y/x)*D_j));
posX2=locX+1+(1.0*D_j);
inX=posX2;
inY=posY2;



if(posY2==inY){
if(maze[inY-1][inX]!=' '){
if(maze[inY-1][inX]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}

PrintMaze(r,c,maze);
break;}}}

if(posY2==inY){
if(maze[inY][inX]!=' '){
if(maze[inY][inX]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}  

PrintMaze(r,c,maze);
break;}}}

if(posY2!=inY){
if(maze[inY][inX]!=' '){
if(maze[inY][inX]=='|'&&maze[inY-1][inX-1]==' '){checkWall++;x=(x*-1);locX=posX2,locY=posY2;break;}
else{checkWall=0;
maze[inY][inX-1]=color;
no=point;
point=point+DestroyBricks(r,c,maze,inX-1,inY);
if(point>no){printf("You got %d points. Score: %d\n",point-no,point);}  

PrintMaze(r,c,maze);
break;}}}

++D_j;


}//while

}//if -1*x>-1*y







}//x>0***********************






}//while

printf("Game is over. Your score is %d!\n",point);

return 0;}

#include <iostream>
#include <fstream>
#include <string>
#include<time.h>
using namespace std;
bool placed = true;

char**placeWordRight( char**grid,char* & word,int row,int col)
{
	int len= strlen(word),cont=0;
	 for(int i = 0; i < len; i++)						//check if positions are empty
		{
            if((grid[row][col+i] == '.') || (grid[row][col+i] == word[i]))
			{
				cont++;
			}
		}
			if(cont==len)
			{
				for(int i = 0; i < len; i++)
				grid[row][col+i] = word[i];
			}
            else
			{
                placed = false;
                return grid;		
            } 
			return grid;

}
char**placeWordDown( char**grid,char* & word,int row,int col)
{
	int len=strlen(word),cont=0;
	for(int i=0;i<len;i++)
			{
				if(grid[row+i][col]=='.'||(grid[row+i][col] == word[i]))
				cont++;
			}
			if(cont==len)
			{
			for(int i=0;i<len;i++)
			grid[row+i][col] = word[i];
			}
			else{
                placed = false;
                return grid;		   
			}
			return grid;
}
char**placeWordLeft( char**grid,char* & word,int row,int col)
{
	
	int len=strlen(word),cont=0;
	for(int i=0; i<len;i++)
			{
				if((grid[row][col-i] == '.') || (grid[row][col-i] == word[i]))
					cont++;
			}
			if(cont==len)
			{
				for(int i=0; i<len;i++)
				grid[row][col-i] = word[i];
			}
            else
			{
                placed = false;
                return grid;
            } 
			return grid;


}
char**placeWordUp( char**grid,char* & word,int row,int col)
{
	int len=strlen(word),cont=0;
	for(int i=0; i<len; i++)
			{
				if(grid[row-i][col]=='.'|| grid[row-i][col]==word[i])
					cont++;
			}
			if(cont==len)
			{
				for(int i=0; i<len; i++)
					grid[row-i][col]=word[i];
			}
				else
				{
					 placed = false;
                        return grid;
                }   
			return grid;


}
char**placeWordUpRight( char**grid,char* & word,int row,int col)
{
	int len=strlen(word),cont=0;
		for(int i=0; i<len; i++)
		{
			if(grid[row-i][col+i]=='.'||grid[row-i][col+i]==word[i])
			{
				cont++;
			}
		}
		if(cont==len)
		{
			for(int i=0; i<len; i++)
			grid[row-i][col+i]=word[i];
		}
		else
		{
				placed = false;
                return grid;
        }  
	return grid;

}
char**placeWordUpLeft( char**grid,char* & word,int row,int col)
{
	int len=strlen(word),cont=0;
	for(int i=0; i<len; i++)
	{
		if(grid[row-i][col-i]=='.'||grid[row-i][col-i]==word[i])
		{
			cont++;
		}
	}
	if(len==cont)
	{
	for(int i=0; i<len; i++)
		grid[row-i][col-i]=word[i];
	}
	else
	{
			placed = false;
            return grid;
    }   


	return grid;
}
char**placeWordDownRight( char**grid,char* & word,int row,int col)
{
	int len=strlen(word),cont=0;
	for(int i=0; i<len; i++)
	{
		if(grid[row+i][col+i]=='.'||grid[row+i][col+i]==word[i])
		{
			cont++;
		}
	}
	if(cont==len)
	{
		for(int i=0; i<len; i++)
		grid[row+i][col+i]=word[i];
	}
	else
	{
			placed = false;
            return grid;
    }   
	return grid;
}
char**placeWordDownLeft( char**grid,char* & word,int row,int col)
{
	int len=strlen(word),cont=0;
	for(int i=0; i<len; i++)
	{
			
		if(grid[row+i][col-i]=='.'|| grid[row+i][col-i]==word[i])
		{
			cont++;
		}
	}
	if(cont==len)
	{
		for(int i=0; i<len; i++)
		grid[row+i][col-i]=word[i];
	}

	else
	{
			placed = false;
			return grid;
	} 


	return grid;
}
char** placeWord(char ** &grid, char*& word, int row,int col,int dir,int colS,int rowS)
{
	int len=strlen(word);
	int cont=0;
	switch(dir)
	{
	case 1:								//right
		if((colS - col) <len )
		{									//not enough space towards right
                placed = false;
                return grid;
            }
		else											
			grid=placeWordRight(grid,word,row,col);
		break;

	case 2:							//down
		if((rowS-row)<len)
		{
			placed =false;
			return grid;
		}
		else
			grid= placeWordDown(grid,word,row,col);
		break;

	case 3:
		if(col+1<len)										//left
		{
			  placed = false;
                return grid;
        }
		else
			  grid=placeWordLeft(grid,word,row,col);
		break;

	case 4:
		if(row+1<len)								//up
		{
			 placed = false;
                return grid;
		}
		else
			grid= placeWordUp(grid,word,row,col);
		break;

	case 5:								//upright
		if(row+1<len||(colS-col)<len)
		{
			placed = false;
                return grid;
		}
		else
			grid= placeWordUpRight(grid,word,row,col);
		break;

	case 6:							//upleft
		if(col+1<len||(row+1)<len)
		{
			placed = false;
                return grid;
		}
		else
			grid=placeWordUpLeft(grid,word,row,col);
		break;
		case 7:							//downright
		if(colS-col<len||(rowS-row)<len)
		{
			placed = false;
               return grid;
		}
		else
			grid=placeWordDownRight(grid,word,row,col);
		break;

		case 8:							//downleft
		if(col+1<len||(rowS-row)<len)
		{
				placed = false;
                return grid;
		}
		else
			grid= placeWordDownLeft(grid,word,row,col);
		break;

		}
	return grid;
}
bool checkWordRight(int row, int col, char words[], char** matrix ,ofstream & out)
{
	int len=strlen(words),k=0;
	for(int i=0; i<row;i++)		//RIGHT
	{
		for(int j=0; j<col;j++)
		{
			if(words[k]==matrix[i][j])
			{
				if(k<len-1&&j+1<col)
				{
					if(words[k+1]==matrix[i][j+1])
						k++;
				}
				else
					k++;
			} 
			else
			{
				k=0;
			}
			if(k==len)
			{
				out<<endl<<words<<" found at "<<endl;
				out<<"( "<<i<<" , "<<j-len+1<<" ) "<<" , "<<"( "<<i<<" , "<<j<<" )"<<endl; 
				cout<<endl<<words<<" found at "<<endl;
				cout<<"( "<<i<<" , "<<j-len+1<<" ) "<<" , "<<"( "<<i<<" , "<<j<<" )"<<endl; 
				return true;
			}
		}
		k=0;
	}
	return false;
}
bool checkWordLeft(int row, int col, char words[], char** matrix ,ofstream & out)
{
	int len= strlen(words);
	int k=len-1;
		 int g=0;

	 for(int i=0; i<row;i++)		//LEFT
	{
		for(int j=0; j<col;j++)
		{
			if(words[k]==matrix[i][j])
			{
				if(k>0&&j+1<col)
				{
					if(words[k-1]==matrix[i][j+1])
					{
						k--;
						g++;
					}
				}
				else
				{
					k--;
					g++;
				}
			}
			else
			{
				k=strlen(words)-1;
				g=0;
			}
			if(g==len)
			{
				out<<endl<<words<<" found at "<<endl;
				out<<"( "<<i<<" , "<<j<<" ) "<<" , "<<"( "<<i<<" , "<<j-len+1<<" )"<<endl; 
				cout<<endl<<words<<" found at "<<endl;
				cout<<"( "<<i<<" , "<<j<<" ) "<<" , "<<"( "<<i<<" , "<<j-len+1<<" )"<<endl; 
				return true;
			}
		}
		k=len-1;
	}
	  return false;
}
bool checkWordDown(int row, int col, char words[], char** matrix ,ofstream & out)
{
	 int len = strlen(words),k=0;
	 for(int i=0; i<col;i++)		//DOWN
	{
		for(int j=0; j<row;j++)
		{
			if(words[k]==matrix[j][i])
			{
				if(k<len-1&&j+1<row)
				{
					if(words[k+1]==matrix[j+1][i])
						k++;
				}
				else
				{
					k++;
				}

			}
			else
			{
				k=0;
			}
			if(k==len)
			{
				

				out<<endl<<words<<" found at "<<endl;
				out<<"( "<<j-len+1<<" , "<<i<<" ) "<<" , "<<"( "<<j<<" , "<<i<<" )"<<endl;  
				cout<<endl<<words<<" found at "<<endl;
				cout<<"( "<<j-len+1<<" , "<<i<<" ) "<<" , "<<"( "<<j<<" , "<<i<<" )"<<endl;  
				return true;
			}
		}
		k=0;
	}
	  return false;
}
bool checkWordUp(int row, int col, char words[], char** matrix ,ofstream & out)
{
	int len = strlen(words);
	int k=len-1,g=0;
	 for(int i=0; i<col;i++)		//UP
	{
		for(int j=0; j<row;j++)
		{
			if(words[k]==matrix[j][i])
			{
				if(k>0 &&j+1<row)
				{
					if(words[k-1]==matrix[j+1][i])
					{
						k--;
						g++;
					}
				}
				else
				{
					k--;
					g++;
				}
			}
			else
			{
					k=len-1;
					g=0;
			}
			if(g==len)
			{
				out<<endl<<words<<" found at "<<endl;
				out<<"( "<<j<<" , "<<i<<" ) "<<" , "<<"( "<<j+1 -len<<" , "<<i<<" )"<<endl; 
				cout<<endl<<words<<" found at "<<endl;
				cout<<"( "<<j<<" , "<<i<<" ) "<<" , "<<"( "<<j+1 -len<<" , "<<i<<" )"<<endl; 
				return true;
			}
		}
		k=len-1;
		g=0;
	}
	 return false;
}
bool checkWordDiagnolTopLeftToBottomRight(int row, int col, char words[], char** matrix ,ofstream & out)
{
	int temp= strlen(words);
	int len=temp,k=0;		//diagnolly down 
	int i1=0,j1=0;
	for(int i=0 ; i<row;i++)
	{
		for(int j=0; j<col;j++)
		{
			k=0;
			if(matrix[i][j]==words[k])
			{
				i1=i;
				j1=j;
				temp=len;
				while(temp)
				{
					if( i1< row && j1 < col && matrix[i1][j1]==words[k]  && k <=len )
					{
						i1++;
						j1++;
						k++;
					}
				temp--;
				}
				if(i==(i1-len) && i1 < row && j1 < col && k ==len)
				{
					out<<endl<<words<<" found at "<<endl;
					out<<"( "<<i<<" , "<<j<<" ) "<<" ,"<<" ( "<<i+len-1<<" , "<<j+len-1<<" )"<<endl;
					cout<<endl<<words<<" found at "<<endl;
					cout<<"( "<<i<<" , "<<j<<" ) "<<" ,"<<" ( "<<i+len-1<<" , "<<j+len-1<<" )"<<endl;
					return true;
				}
			}
		}
	}
	return false;


}
bool checkWordDiagnolBottomLeftToTopRight(int row, int col, char words[], char** matrix ,ofstream & out)
{
	int temp= strlen(words);
	int len=temp,k=0;		
	int i1=0,j1=0;
	for(int i=0 ; i<row;i++)
		{
			for(int j=0; j<col;j++)			//dagnolly left to right bottom to top
			{
				k=0;
				if(matrix[i][j]==words[k])
				{
					i1=i;
					j1=j;
					temp=len;
					k=0;
					while(temp)
					{
						if( i1>=0 && j1 >=0 && matrix[i1][j1]==words[k] && k <=len )
						{
							i1--;
							j1--;
							k++;
						}
						temp--;
					}
					if(i==(i1+len))
					{
						out<<endl<<words<<" found at "<<endl;
						out<<"( "<<i<<" , "<<j<<" ) "<<" ,"<<" ( "<<i-len+1<<" , "<<j-len+1<<" )"<<endl;
						cout<<endl<<words<<" found at "<<endl;
						cout<<"( "<<i<<" , "<<j<<" ) "<<" ,"<<" ( "<<i-len+1<<" , "<<j-len+1<<" )"<<endl;
						return true;
					}	
				}
			}
		}


	return false;
}
bool checkWordDiagnolBottomRightToTopLeft(int row, int col, char words[], char** matrix ,ofstream & out)
{
	
	int temp= strlen(words);
	int len=temp,k=0;		
	int i1=0,j1=0;
	for(int i=0 ; i<row;i++)			//Diagonally from Bottom-Right to Top-Left,
		{
			for(int j=0; j<col;j++)
			{
				k=0;
				if(matrix[i][j]==words[k])
				{
					i1=i;
					j1=j;
					temp=len;
					k=0;
					while(temp)
					{
						if(i1<row)
						if(	i1<row && j1 >=0 && matrix[i1][j1]==words[k] &&k <=len )
						{
							i1++;
							j1--;
							k++;
						}
						temp--;
					}
					if(i==(i1-len) && j==(j1+len))
					{
						out<<endl<<words<<" found at "<<endl;
						out<<"( "<<i<<" , "<<j<<" ) "<<" ,"<<" ( "<<(i+len-1)<<" , "<<j-len+1<<" )"<<endl;
						cout<<endl<<words<<" found at "<<endl;
						cout<<"( "<<i<<" , "<<j<<" ) "<<" ,"<<" ( "<<(i+len-1)<<" , "<<j-len+1<<" )"<<endl;
						return true;
					}
				}
			}
		}


	return false;
}
bool checkWordDiagnolTopRightToBottomLeft(int row, int col, char words[], char** matrix ,ofstream & out)
{
	int temp= strlen(words);
	int len=temp,k=0;		
	int i1=0,j1=0;
	for(int i=0 ; i<row;i++)				//Diagonally from Top-Right to Bottom-Left
		{
			for(int j=0; j<col;j++)
			{
				k=0;
				if(matrix[i][j]==words[k])
				{

					i1=i;
					j1=j;
					temp=len;
					k=0;
					while(temp)
					{
						if( i1>=0&& matrix[i1][j1]==words[k] && j1 >=0 &&k <=len )
						{
							i1--;
							j1++;
							k++;
						}
						temp--;
					}
					if(i==(i1+len)&&j==(j1-len))
					{
						out<<endl<<words<<" found at "<<endl;
						out<<"( "<<i<<" , "<<j<<" ) "<<" ,"<<" ( "<<(i-len+1)<<" , "<<j+len-1<<" )"<<endl;
						cout<<endl<<words<<" found at "<<endl;
						cout<<"( "<<i<<" , "<<j<<" ) "<<" ,"<<" ( "<<(i-len+1)<<" , "<<j+len-1<<" )"<<endl;
						return true;
					}
			}				
		}
	}



	return false;
}

bool checkWord(ofstream & out,int cas,int row,int col,char words[],char ** & matrix)
{
	if(checkWordRight(row,col,words,matrix,out))
		return true;
	else
		if(checkWordLeft(row,col,words,matrix,out))
		return true;
	else
		if(checkWordDown(row,col,words,matrix,out))
		return true;
	else
		if(checkWordUp(row,col,words,matrix,out))
		return true;
	else
		if(checkWordDiagnolTopLeftToBottomRight(row,col,words,matrix,out))
		return true;
	else
		if(checkWordDiagnolBottomLeftToTopRight(row,col,words,matrix,out))
		return true;
	else
		if(checkWordDiagnolBottomRightToTopLeft(row,col,words,matrix,out))
		return true;
	else
		if(checkWordDiagnolTopRightToBottomLeft(row,col,words,matrix,out))
		return true;
	else
	 return false;

}

char** generateGrid(char words[][30], int rowS,int colS)
{
	char **grid=new char*[rowS];
		for(int i=0;i<rowS;i++)
			grid[i]=new char[colS];
		for(int i=0;i<rowS;i++)					//empty the grid
		{
			for(int j=0; j<colS;j++)
			{

			grid[i][j]='.';

			}
		}

			for(int i=0; *words[i] !='\0';i++)		//placing the words first
			{
				char *ptr=words[i];
				while(true)
				{
					placed = true;
					//generating a random position and direction
					int row = rand() % rowS;
					int col = rand() % colS;
					int direction = 1 + (rand() % 8);
					grid=placeWord(grid,ptr,row,col,direction,colS,rowS);
					if(placed==true)
					{
						break;
					}
				}
			}
					//fill the grid
			char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' }; 
			for(int x = 0; x < rowS; x++){
				for(int y = 0; y < colS; y++){
					if(grid[x][y] == '.'){
						grid[x][y] = alphabet[rand() % 26];
					}
				}
			}
			return grid;
}
void deleteFiles(char** grid, int row)
{
	for(int i=0 ;i<row; i++)
	delete[] grid[i];
	delete[] grid;
}

int main()
{
	cout<<"===========================================Welcome to WordSearch======================================================"<<endl<<endl<<endl;
	cout<<"\n\n1) Create Grid\n2) Search Words from Grid\n3) Quit"<<endl<<endl<<endl;
	char choice='a';
	cout<<"Enter s to search words from grid ...........\nEnter c to create grid.............\nEnter Q to quit............"<<endl;
	cin>>choice;

	/*this program takes the max 15 words from a file named input.txt and generate a grid of 15X15 of words randomly placed in it*/
	while(choice!='Q'&&choice!='q')
	{
		switch(choice)
		{
		case 'c':
		case 'C':
			{
				srand(time(0));
				char words[30][30];					//max 15 words
				string filename,filename2;
				cout<<"\n\nEnter the name of file in which list of words is present"<<endl;
				cin>>filename;
				ifstream wordlist(filename);		//input.txt
				if(wordlist)
				{
					int num;
					cout<<"enter number of total words "<<endl;
					cin>>num;
						int rowS,colS;
						cout<<"Number of rows in the grid"<<endl;
						cin>>rowS;
						cout<<"Number of columns in the grid"<<endl;
						cin>>colS;
						int x=0;
						for(x=0;x<num;x++)			//length of the word should be smaller than 15
						{
							wordlist.getline(words[x],15);
							if(strlen(words[x])>rowS||strlen(words[x])>colS)
							{
								cerr<<"Grid cannot be generated because of smaller length of rows/columns"<<endl;
								break;
							}
							*words[x]='\0';
						}
						*words[x]='\0';
						if(x==num)
							{
								char** grid= generateGrid(words,rowS,colS);

								//ofstream out("output1.txt");
								cout<<"Enter Name of the output file where the grid needs to be placed"<<endl;
								cin>>filename2;
								ofstream out(filename2);
								for(int i=0;i<rowS;i++)				//place in file
								{
									for(int j=0; j<colS;j++)
									{
									out<<grid[i][j]<<"    ";
									cout<<grid[i][j]<<"    ";
									}
									out<<endl;
									cout<<endl;
								}
								deleteFiles(grid,rowS);								//deallocating memory on heapS
								cout<<"grid is created successfully and palced in file named "<<filename2<<endl<<endl;
							}
						cout<<"enter any  character key to return to home page "<<endl;
						char a;
						cin>>a;
				}
				else
					cerr<<"file cannot be opened"<<endl;
				break;
			}
			case 's':
			case 'S':
			
			{
				int cas,row,col;
				char words[20][20];
				string filename1,filename2,filename3;
				cout<<"\n\nEnter the name of file in which grid is present"<<endl;
				cin>>filename1;
				cout<<"\n\nEnter the name of file in which data is present"<<endl;
				cin>>filename2;
				ifstream input (filename1);
				ifstream input1 (filename2);
				input1>>row>>col;					//Enter the size of grid in format of row  and column
				char **matrix= new char*[row];
				for(int i=0; i<row;i++)
					matrix[i]=new char[col];
				for(int i=0; i<row;i++)			//input matrix grid
				{
					for(int j=0;j<col;j++)
					{
						input>>matrix[i][j];
					}
				}
				input1>>cas;		//number of cases
				for(int i=0; i<cas;i++)
				{
					input1>>words[i];
					if(strlen(words[i])<2)
					{
						cerr<<"enter word of length greater than 2 "<<endl;
						input1>>words[i];
					}
				}
				
				cout<<"Enter name of file to which words coordinates are to be placed"<<endl;
				cin>>filename3;
				ofstream out(filename3);
		
				for(int i=0; i<cas;i++)
				if(!checkWord(out,cas,row,col,words[i],matrix))
				{
					out<<endl<<words[i]<< "  Not found"<<endl;
					cout<<endl<<words[i]<< "  Not found"<<endl;
				}
				deleteFiles(matrix,row);		//deallocate memory 
				cout<<"Words are searched successfully"<<endl<<endl;
				cout<<"enter any character key to return to home page "<<endl;
						char a;
						cin>>a;
				break;
			}
		default:
			{
				if(choice!='q'&&choice!='Q')
				cout<<"\n\n!!enter APPROPRIATE CHOICE!! "<<endl;
				
			}
		}
		cout<<"\n\n1) Create Grid\n2) Search Words from Grid\n3) Quit"<<endl<<endl<<endl;
		cout<<"\n\nEnter s to search words from grid ...........\nEnter c to create grid.............\nEnter Q to quit............"<<endl<<endl;
		cin>>choice;

	}

			if(choice=='q'||choice=='Q')
			{
				cout<<"leaving so soon.... Good Bye;)"<<endl<<endl<<endl;
				//return 0;
			}

	system("pause");
	return 0;
}
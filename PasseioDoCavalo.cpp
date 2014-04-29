#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int move[8][2]={1,2, 2,1, 2,-1, 1,-2, -1,-2, -2,-1, -2,1, -1,2};

class tour {
	vector< vector< int > > board;
	int sx, sy, size;
		
public:
	bool findtour(tour& , int );
	
        // Construtor
	tour(int s = 8, int startx = 0, int starty = 0)
		:sx(startx), sy(starty), size(s)
	{ printf ("Resolvendo... \nMatriz %dx%d Posicao Inicial X:%d e Y:%d\n\nby Elves\n", s,s,startx,starty);
  // Obter da matriz ao tamanho x tamanho
		board.resize(size);
		for(int i = 0; i < size; ++i)
			board[i].resize(size);


		for(int i = 0; i < size; ++i)
		  for(int j = 0; j < size; ++j) 
			board[i][j] = -1;

		board[sx][sy] = 0;

		if(!findtour(*this, 0)) 
		  cout << "Solucao NAO encontrada nessa posicao inicial\n ";
    system("pause");
	}		
	
	tour(const tour& T): sx(T.sx), sy(T.sy), size(T.size){
		this->board.resize(size);
		for(int i = 0; i < size; ++i)
			board[i].resize(size);

		for(int i = 0; i < size; ++i)
		  for(int j = 0; j < size; ++j)	
		    board[i][j] = T.board[i][j];
	}
	
        friend std::ostream& operator<<
	  ( std::ostream& os, const tour& T );
};

std::ostream& operator<<( std::ostream& os, const tour& T ){
  os << endl;
  int size = T.size;

  os << " +"; for(int i = 0; i < size*5-1; ++i) os << "-";
  os << "+\n";

  for(int i = 0; i < size; ++i){ 
    os << " | "; 
    for(int j = 0; j < size; ++j)
      os <<  setw(2) << T.board[i][j] << " | ";
    os << endl;

    os << " +"; for(int i = 0; i < size*5-1; ++i) os << "-";
    os << "+\n";

  }

   system("pause");
  return os;
}

// Função recursiva
bool tour::findtour(tour& T, int imove){
        if(imove == (size*size - 1)) return true;

	int cx = T.sx;
	int cy = T.sy;
        int cs = T.size;

        for ( int i = 0; i < 8; ++i){
	  int tcx = cx + move[i][0];
	  int tcy = cy + move[i][1];
	  if (

                  (tcx >= 0) &&  (tcy >= 0)  &&  (tcx < cs) &&  (tcy < cs) &&

                  (T.board[tcx][tcy] == -1)
             ){
		tour temp(T);
		temp.board[tcx][tcy] = imove+1;
		temp.sx = tcx;
		temp.sy = tcy;
		if(findtour(temp, imove+1)) {
		  cout << "Solucao encontrada\n";
		  cout << temp << endl;
		  exit(1);
		}
   	  }
        }
		
        return false;
}


int main(void){
	tour T;
	return 0;
}

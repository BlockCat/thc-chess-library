#include <stdio.h>
#include <iostream>
#include <string>

#include <thc.h>

using namespace std;
using namespace thc;

int main() {
    printf("Hello world\n");
    ChessPosition* pos = new ChessPosition();

    uint32_t hash = pos->HashCalculate();    
    printf("Hash: %d\n", hash);

    ChessRules* rules = new ChessRules(*pos);
    vector<Move> moves;
    rules->GenLegalMoveList(moves);

    cout << "possible moves: " << moves.size() << endl;

    Move* nmove = new Move();
    nmove->src = e2;
    nmove->dst = e4;
    rules->PlayMove(*nmove);
    
    hash = rules->HashCalculate();    
    printf("Hash: %d\n", hash);  

    cout << "after a move" << rules->ToDebugStr() << endl;
}

#include <iostream>
#include <string>
using namespace std;

class Game {
        string name;
        string creator;
        int players;
        int time;
        int price;

    public:
        Game(){
            name = "Chess";
            creator = "Donald Trump";
            players = 2;
            time = 30;
            price = 200;
        }
        
        Game(string n, string c, int p, int t, int pr): name(n),creator(c),players(p),time(t),price(pr) {}

        void setName(string n){
            name=n;
        }
        void setCreator(string c){
            creator=c;
        }
        void setPlayers(int p){
            players=p;
        }
        void setTime(int t){
            time=t;
        }
        void setPrice(int pr){
            price=pr;
        }

        void print(){
            cout<<name<<endl;
            cout<<creator<<endl;
            cout<<players<<endl;
            cout<<time<<endl;
            cout<<price<<endl;
        }

        
};

int main(){
    Game game1;
    Game game2("Monopoly","gameshop123",4,120,500);
    Game game3("Domino","rozetkaua",3,20,345);

    game1.setCreator("Unknown creator");
    game2.setPrice(700);
    game3.setTime(15);

    game1.print();
    game2.print();
    game3.print();
}
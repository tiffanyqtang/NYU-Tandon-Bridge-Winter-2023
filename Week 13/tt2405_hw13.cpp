/*Making a grid(2d matrix of orgranism pointer), where there will be spaces(-), ants(o), and doodlebugs(X) as inherited classes of organism
I think this works. I can't look at the word doodlebug anymore*/

#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int ROWS = 20;
const int COLUMNS = 20;
const int TOTAL_GRIDS = 400;
const int START_ANTS = 100;
const int START_DOODLE= 5;
const int ANT_BREED = 3;
const int DOODLE_BREED = 8;

class Organism{
protected:
    int x, y, age;
    char symbol;
    bool isAlive;
public:
    Organism();
    Organism(int startX, int startY, int update_age);
    void set_x(int update_x){
        x = update_x;
    }
    void set_y(int update_y){
        y = update_y;
    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
    int get_age(){
        return age;
    }
    void set_age(int update_age){
        age = update_age;
    }
    bool get_isAlive(){
        return isAlive;
    }
    void set_isAlive(bool condition){
        isAlive = condition;
    }
    virtual char return_symbol(){
        return symbol;
    }
    virtual void get_symbol(){// should only cout the inherited class symbol
        cout<<"Problem with get symbol";
    }
    void set_symbol(char update_symbol){
        symbol = update_symbol;
    }
   
    virtual void move(){
        cout<<"There is a problem with move";
    }
    virtual void breed(){
        cout<<"There is a problem with breed";
    }
   
};
Organism::Organism(){
    x = -1;
    y = -1;
    age = 0;
    isAlive = false;
}
Organism::Organism(int startX, int startY, int update_age){
    x = startX;
    y = startY;
    age = update_age;
}

class Space : public Organism{//needs to be a class so the organism pointer can point to it, will use to check if free space
public:
    Space();
    virtual void get_symbol(){
        cout<<symbol;
    }
    virtual char return_symbol(){
        return symbol;
    }
private:
    char symbol;
};
Space::Space() : Organism(), symbol('-'){};


class Ant : public Organism{
private: 
    char symbol;
public:
    Ant();
    void get_symbol(){
        cout<<symbol;
    }
    char return_symbol(){
        return symbol;
    }
    void move(Organism *gridArray[ROWS][COLUMNS], Space spaceArr[]);
    void breed(Organism *gridArray[ROWS][COLUMNS], Ant antArr[], int &antCount);// make this apart of base class, with input on breed date? code would be same for both
};
Ant:: Ant() : Organism(), symbol('o'){};

int nextAntIndex(Ant antArr[], int &antCount){
    int nextIndex = 0;
    for(int i = 0; i < TOTAL_GRIDS; i++){
        if(antArr[i].get_isAlive()== false){
            nextIndex = i;
            i = 400;
        }
    }
    return nextIndex;
}

void Ant::move(Organism *gridArray[ROWS][COLUMNS], Space spaceArr[]){
        set_age(get_age() + 1);
        int direction = (rand()%4) + 1; //pick random direction
        if(direction == 1){//to the right
                if((get_x()+ 1 <= 19) && (gridArray[get_x()+1][get_y()] -> return_symbol() =='-')){//within bounds and symbol is a space using polymorphism
                    gridArray[get_x() + 1][get_y()] = this;//make ant via this pointer
                    gridArray[get_x()][get_y()] = &spaceArr[0];//make old space into a space('-')
                    set_x(get_x() + 1);//set new x for my ant

                }
        }
        else if(direction == 2){//to the left
                if((get_x()- 1 >= 0) && (gridArray[get_x()-1][get_y()] -> return_symbol() =='-')){
                    gridArray[get_x()-1][get_y()] = this;
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_x(get_x() - 1);
                }
        }
        else if(direction == 3){//down
                if((get_y()+ 1 <= 19) && (gridArray[get_x()][get_y()+1] -> return_symbol() =='-')){
                    gridArray[get_x()][get_y()+1] = this;
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_y(get_y() + 1);
                }
        }
        else if(direction == 4){//up
                if((get_y()- 1 >= 0) && (gridArray[get_x()][get_y()-1] -> return_symbol() =='-')){
                    gridArray[get_x()][get_y()-1] = this;
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_y(get_y() - 1);
                }
        }
    }

void Ant::breed(Organism *gridArray[ROWS][COLUMNS], Ant antArr[], int &antCount){
    
    if((get_age()%ANT_BREED == 0)&&(get_age()>0))
    
        for(int i = 1; i <=4; i++){//loop through 4 directions to see if theres open spot to breed
            if(i==1){
                int nextIndex = nextAntIndex(antArr, antCount);
                if((get_x()+ 1 <= 19) && (gridArray[get_x()+1][get_y()] -> return_symbol() =='-')){
                    gridArray[get_x() + 1][get_y()] = &antArr[nextIndex];//make ant via this pointer
                    antArr[nextIndex].set_x(get_x() + 1);
                    antArr[nextIndex].set_y(get_y());//gotta update the new location
                    antArr[nextIndex].set_isAlive(true);
                    break;
                }
            }
            else if(i ==2){
                int nextIndex = nextAntIndex(antArr, antCount);
                if((get_x()- 1 >= 0) && (gridArray[get_x()-1][get_y()] -> return_symbol() =='-')){
                    gridArray[get_x()-1][get_y()] = &antArr[nextIndex];//make ant via this pointer
                    antArr[nextIndex].set_x(get_x() - 1);
                    antArr[nextIndex].set_y(get_y());
                    antArr[nextIndex].set_isAlive(true);
                    break;

                }
            }
            else if(i == 3){
                int nextIndex = nextAntIndex(antArr, antCount);
                if((get_y()+ 1 <= 19) && (gridArray[get_x()][get_y()+1] -> return_symbol() =='-')){
                    gridArray[get_x()][get_y()+1] = &antArr[nextIndex];//make ant via this pointer
                    antArr[nextIndex].set_x(get_x());
                    antArr[nextIndex].set_y(get_y()+1);
                    antArr[nextIndex].set_isAlive(true);
                    break;
                }
            }
            else if(i == 4){
                int nextIndex = nextAntIndex(antArr, antCount);
                if((get_y()- 1 >= 0) && (gridArray[get_x()][get_y()-1] -> return_symbol() =='-')){
                    gridArray[get_x()][get_y()-1] = &antArr[nextIndex];//make ant via this pointer
                    antArr[nextIndex].set_x(get_x());
                    antArr[nextIndex].set_y(get_y()-1);
                    break;
                }
            }
        }
}
    
    
class Doodlebug : public Organism{
public:
    Doodlebug();
    virtual char return_symbol(){
        return symbol;
    }
    virtual void get_symbol(){
        cout<<symbol;
    }
    void set_hungryCount(int newCount){
        hungryCount = newCount;
    }
    int get_hungryCount(){
        return hungryCount;
    }
    void move(Organism * gridArray[ROWS][COLUMNS], Space spaceArr[], Doodlebug doodleArr[], bool eaten);
    void breed(Organism *gridArray[ROWS][COLUMNS], Doodlebug doodleArr[], int &doodleCount);
    bool didEat(Organism * gridArray[ROWS][COLUMNS], Space spaceArr[], Doodlebug doodleArr[]);
    //eat?? can maybe combine in move

    void hungry(Organism *gridArray[ROWS][COLUMNS], Doodlebug doodleArr[], Space spaceArr[]){
        if(get_hungryCount() == 3){
                set_isAlive(false);
                set_age(0);
                gridArray[get_x()][get_y()] =  &spaceArr[0];
            }
    }
private: 
    char symbol;
    int hungryCount;
};

Doodlebug::Doodlebug() : Organism(), symbol('X'), hungryCount(0){};

int nextDoodleIndex(Doodlebug doodleArr[], int &doodlecount){
    int nextIndex = 0;
    for(int i = 0; i < TOTAL_GRIDS; i++){
        if(doodleArr[i].get_isAlive()== false){
            nextIndex = i;
            i = 400;
        }
    }
    return nextIndex;
}
bool Doodlebug::didEat(Organism * gridArray[ROWS][COLUMNS], Space spaceArr[], Doodlebug doodleArr[]){
        
        for(int i = 1; i <=4; i++){//loop through 4 directions to see if theres ant next to- same code style as breed. 
            if(i==1){
                if((get_x()+ 1 <= 19) && (gridArray[get_x()+1][get_y()] -> return_symbol() =='o')){
                    gridArray[get_x() + 1][get_y()]-> set_isAlive(false);//kill ant
                    gridArray[get_x() + 1][get_y()] ->set_age(0);
                     gridArray[get_x() + 1][get_y()] = this;
                     gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_x(get_x()+1);//update doodle new location
                    set_hungryCount(0);
                    set_age(get_age()+1);
                    return true;
                    break;
                }
            }
            else if(i ==2){
                if((get_x()- 1 >= 0) && (gridArray[get_x()-1][get_y()] -> return_symbol() =='o')){
                    gridArray[get_x()-1][get_y()] ->set_isAlive(false);
                    gridArray[get_x()-1][get_y()]->set_age(0);
                    gridArray[get_x()-1][get_y()]= this;
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_x(get_x()-1);
                    set_hungryCount(0);
                    set_age(get_age()+1);
                    return true;
                    break;

                }
            }
            else if(i == 3){
                if((get_y()+ 1 <= 19) && (gridArray[get_x()][get_y()+1] -> return_symbol() =='o')){
                    gridArray[get_x()][get_y()+1] -> set_isAlive(false);
                    gridArray[get_x()][get_y()+1] -> set_age(0);
                    gridArray[get_x()][get_y()+1] =this; 
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_y(get_y()+1);
                    set_hungryCount(0);
                    set_age(get_age()+1);
                    return true;
                    break;
                }
            }
            else if(i == 4){
                if((get_y()- 1 >= 0) && (gridArray[get_x()][get_y()-1] -> return_symbol() =='o')){
                    gridArray[get_x()][get_y()-1] -> set_isAlive(false);
                    gridArray[get_x()][get_y()-1]-> set_age(0);
                    gridArray[get_x()][get_y()-1]= this;
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_y(get_y()-1);
                    set_hungryCount(0);
                    set_age(get_age()+1);
                    return true;
                    break;
                }
            }
            else{
                return false;
            }
        }
       
}

void Doodlebug::move(Organism *gridArray[ROWS][COLUMNS], Space spaceArr[], Doodlebug doodleArr[], bool eaten){//must eat ant if it is next to it
    
    //bool eaten = false;
        if(eaten ==false ){
            set_age(get_age()+1);
            int direction = (rand()%4) + 1;
            if(direction == 1){//to the right
                if((get_x()+ 1 <= 19) && (gridArray[get_x()+1][get_y()] -> return_symbol() =='-')){//within bounds and symbol is a space using polymorphism
                    gridArray[get_x() + 1][get_y()] = this;
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_x(get_x() + 1);
                    set_hungryCount(get_hungryCount()+1);
                }
            }
            else if(direction == 2){//to the left
                if((get_x()- 1 >= 0) && (gridArray[get_x()-1][get_y()] -> return_symbol() =='-')){
                    gridArray[get_x()-1][get_y()] = this;
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_x(get_x() - 1);
                    set_hungryCount(get_hungryCount()+1);
                }
            }
            else if(direction == 3){//down
                if((get_y()+ 1 <= 19) && (gridArray[get_x()][get_y()+1] -> return_symbol() =='-')){
                    gridArray[get_x()][get_y()+1] = this;
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_y(get_y() + 1);
                    set_hungryCount(get_hungryCount()+1);
                }
            }
            else if(direction == 4){//up
                if((get_y()- 1 >= 0) && (gridArray[get_x()][get_y()-1] -> return_symbol() =='-')){
                    gridArray[get_x()][get_y()-1] = this;
                    gridArray[get_x()][get_y()] = &spaceArr[0];
                    set_y(get_y() - 1);
                    set_hungryCount(get_hungryCount()+1);
                }
            }
        }
        else{

        }
    }

void Doodlebug::breed(Organism *gridArray[ROWS][COLUMNS], Doodlebug doodleArr[], int &doodleCount){
    int nextIndex = nextDoodleIndex(doodleArr, doodleCount);
    
    if((get_age()% DOODLE_BREED == 0)&&(get_age()>0))
        for(int i = 1; i <=4; i++){//loop through 4 directions to see if theres open spot to breed
            if(i==1){
                if((get_x()+ 1 <= 19) && (gridArray[get_x()+1][get_y()] -> return_symbol() =='-')){
                    gridArray[get_x() + 1][get_y()] = &doodleArr[nextIndex];//make ant via this pointer
                    doodleArr[nextIndex].set_x(get_x() + 1);
                    doodleArr[nextIndex].set_y(get_y());
                    doodleArr[nextIndex].set_isAlive(true);
                    break;
                }
            }
            else if(i ==2){
                if((get_x()- 1 >= 0) && (gridArray[get_x()-1][get_y()] -> return_symbol() =='-')){
                    gridArray[get_x()-1][get_y()] = &doodleArr[nextIndex];//make ant via this pointer
                    doodleArr[nextIndex].set_x(get_x() - 1);
                    doodleArr[nextIndex].set_y(get_y());
                    doodleArr[nextIndex].set_isAlive(true);
                    break;

                }
            }
            else if(i == 3){
                if((get_y()+ 1 <= 19) && (gridArray[get_x()][get_y()+1] -> return_symbol() =='-')){
                    gridArray[get_x()][get_y()+1] = &doodleArr[nextIndex];//make ant via this pointer
                    doodleArr[nextIndex].set_x(get_x());
                    doodleArr[nextIndex].set_y(get_y()+1);
                    doodleArr[nextIndex].set_isAlive(true);
                    break;
                }
            }
            else if(i == 4){
                if((get_y()- 1 >= 0) && (gridArray[get_x()][get_y()-1] -> return_symbol() =='-')){
                    gridArray[get_x()][get_y()-1] = &doodleArr[nextIndex];//make ant via this pointer
                    doodleArr[nextIndex].set_x(get_x());
                    doodleArr[nextIndex].set_y(get_y()-1);
                    doodleArr[nextIndex].set_isAlive(true);
                    break;
                }
            }
        }
}

void initialize_World(Organism* worldArr[ROWS][COLUMNS], Space spaceArr[], Ant antArr[], Doodlebug doodleArr[], int &antCount, int &doodleCount){
    while(doodleCount < START_DOODLE){
        bool isCreated = false;
        int tempX, tempY;
        while(isCreated == false){
            tempX = rand()%20;
            tempY = rand()%20;
            if(worldArr[tempX][tempY] == nullptr){
                worldArr[tempX][tempY] = &doodleArr[doodleCount];
                worldArr[tempX][tempY] -> set_x(tempX);
                worldArr[tempX][tempY] -> set_y(tempY);
                worldArr[tempX][tempY] -> set_isAlive(true);
                doodleCount++;
                isCreated = true;
            }
        }
    }
    while(antCount < START_ANTS){
        bool isCreated = false;
        int tempX, tempY;
        while(isCreated == false){// make sure ant is made on its own square
            tempX = rand()%20;
            tempY = rand()%20;
            if(worldArr[tempX][tempY] == nullptr){
                worldArr[tempX][tempY] = &antArr[antCount];
                worldArr[tempX][tempY] -> set_x(tempX);
                worldArr[tempX][tempY] -> set_y(tempY);
                worldArr[tempX][tempY] -> set_isAlive(true); // ant is now alive
                antCount++;
                isCreated = true;
            }
        }
    }
    for(int y = 0; y < COLUMNS; y++){
        for(int x = 0; x < ROWS; x++ ){
            if(worldArr[x][y] == nullptr){
                worldArr[x][y]= &spaceArr[0]; //make space in world
            }
        }
    }
}

void printWorld(Organism *worldArr[ROWS][COLUMNS]){
    for(int y = 0; y < COLUMNS; y++){
        for(int x = 0; x < ROWS; x++){
            worldArr[x][y] ->get_symbol();
            cout<<" ";
        }
        cout<<endl;
    } 
}

void time_step(Organism* worldArr[ROWS][COLUMNS], Space spaceArr[], Ant antArr[], Doodlebug doodlArr[], int &antCount, int &doodleCount, bool eaten){
    for(int i = 0; i < TOTAL_GRIDS; i++){
        if(doodlArr[i].get_isAlive() == true){
            doodlArr[i].didEat(worldArr, spaceArr, doodlArr);
            doodlArr[i].move(worldArr, spaceArr, doodlArr, eaten);//doodle moves refers back to its position in the world
        }
    }
    for(int i = 0; i < TOTAL_GRIDS; i++){
        if(antArr[i].get_isAlive() == true){
            antArr[i].move(worldArr, spaceArr);
        }
    }
    for(int i = 0; i < TOTAL_GRIDS; i++){
        if(doodlArr[i].get_isAlive()==true){
            doodlArr[i].breed(worldArr, doodlArr, doodleCount);
        }   
    }
    for(int i = 0; i < TOTAL_GRIDS; i++){
        if(antArr[i].get_isAlive()==true){
            antArr[i].breed(worldArr, antArr, antCount);
        }
    }
    for(int i = 0; i < TOTAL_GRIDS; i++){
        if(doodlArr[i].get_isAlive()==true){
            doodlArr[i].hungry(worldArr, doodlArr, spaceArr);
        }
    }
    
    printWorld(worldArr);
}

int main(){
    int timeCount = 1;
    int antCount = 0, doodleCount=0;
    Ant antArr[TOTAL_GRIDS];
    Doodlebug doodleArr[TOTAL_GRIDS];
    Space spaceArr[1];
    Organism * worldArray[ROWS][COLUMNS]; 
    bool eaten;
    
    for(int x = 0; x < ROWS; x++){
        for(int y = 0; y < COLUMNS; y++){
            worldArray[x][y] = nullptr;//pointers have to point to something, start pointing at nullptr
        }
    }
    srand(time(0));

    initialize_World(worldArray, spaceArr, antArr, doodleArr, antCount, doodleCount);
    cout<<"Initializing world..."<<endl;

    printWorld(worldArray);
    cout<<"Press ENTER to start simulation"<<endl;

    while(cin.get()=='\n'){
        cout<<"Time step: "<<timeCount<<endl;

        time_step(worldArray, spaceArr, antArr, doodleArr, antCount, doodleCount, eaten);

        cout<<"Press ENTER for next time step"<<endl;  
        timeCount++;
    }

    return 0;
}
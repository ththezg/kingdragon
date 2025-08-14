/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 2
* Programming Fundamentals Summer 2025
* Date: 28.07.2025
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef H_DRAGON_WARRIORS_H
#define H_DRAGON_WARRIORS_H

#include "main.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Forward declaration
// class MovingObject;
// class ArrayMovingObject
// class DragonWarriorsProgram
// class Position;
// class Configuration;
// class Map;

// class DragonLord;
// class SmartDragon;
// class Warrior;
// class FlyTeam;
// class GroundTeam;

// class BaseItem;
// class BaseBag;
// class TeamBag;

class TestDragonWar;

// ——— Enums ———
enum ElementType     { PATH, OBSTACLE, GROUND_OBSTACLE };
enum DragonType      { SD1, SD2, SD3 };
enum ItemType        { DRAGONSCALE, HEALINGHERB, TRAPENHANCER };

// ——— MapElement ———
class MapElement {
private:
    ElementType type;
    int         req_dmg; 
public:
    MapElement(ElementType t, int r = 0);
    virtual ~MapElement();
    ElementType getType() const;
    int getReqDmg()       const;
};

// ——— Map ———
class Map {
private:
    int           num_rows;
    int           num_cols;
    MapElement ***grid;

public:
    Map(int rows, int cols,
        int num_obst,       Position *obst,
        int num_gro_obst,   Position *gro_obst);
    ~Map();
    bool isValid(const Position & pos, MovingObject * map) const;
    int  getNumRows()     const;
    int  getNumCols()     const;
};

// ——— Position ———
class Position {
private:
    int r_, c_;
public:
    static const Position npos;
    Position(int r = 0, int c = 0);
    Position(const string &str_pos);
    int     getRow()  const;
    int     getCol()  const;
    void    setRow(int r);
    void    setCol(int c);
    string  str()     const;
    bool    isEqual(int in_r, int in_c) const;
};

// ——— MovingObject ———
class MovingObject {
protected:
    int      index;
    Position   pos;
    Map     *  map;
    string    name;

public:
    MovingObject(int index, const Position & pos, Map *map, const string & name = "");
    virtual ~MovingObject();
    virtual Position getNextPosition() = 0;
    Position          getCurrentPosition() const;
    virtual void      move()          = 0;
    virtual string    str()    const = 0;
};

// ——— Warrior ———
class Warrior /* TODO */ {
protected:
    // TODO

public:
    Warrior(int index, const Position & pos, Map * map,
            const string & name, int hp, int damage);
    virtual ~Warrior();
    // TODO
    // getter and setter
    // getBag()  

};

// ——— FlyTeam & GroundTeam ———
class FlyTeam /* TODO */ {
private:
    // TODO

public:
    FlyTeam(int index, const string & moving_rule,
        const Position & pos, Map * map, int hp, int damage);
    // TODO
    // getNextPosition() 
    // move()
    // str()
    // attack()

};

class GroundTeam /* TODO */ {
private:
    // TODO

public:
    GroundTeam(int index, const string & moving_rule,
        const Position & pos, Map * map, int hp, int damage);
    // TODO
    // getNextPosition()
    // move
    // str
    // trap
    // getter and setter
    
};

// ——— DragonLord ———
class DragonLord /* TODO */ {
private:
    // TODO

public:
    DragonLord(int index, const Position & pos, Map * map,
               FlyTeam *flyteam1, FlyTeam *flyteam2);
    // TODO
    // getNextPosition()
    // move
    // str
    
};

// ...................
// ——— SmartDragon ———
// ——— BaseItem ———
// ——— BaseBag ———
// ...................

// ——— ArrayMovingObject ———
class ArrayMovingObject {
private:
    // TODO

public:
    ArrayMovingObject(int capacity);
    ~ArrayMovingObject() ;
    // TODO
    // isFull, add, str,...

};

// ——— Configuration ———
class Configuration {
    friend class DragonWarProgram;

private:
    // TODO

public:
    Configuration(const string & filepath);
    ~Configuration();
    string str() const;
    // TODO

};

// ——— DragonWarriorsProgram ———
class DragonWarriorsProgram {
private:
    // Sample attributes

    Configuration      *config;

    FlyTeam            *flyteam1;
    FlyTeam            *flyteam2;
    GroundTeam         *groundteam;
    DragonLord         *dragonlord;

    Map                *map;
    ArrayMovingObject  *arr_mv_objs;
    
public:
    DragonWarriorsProgram(const string &config_file_path);
    
    bool   isStop() const;

    void printResult() const {
        if (flyteam1->getCurrentPosition().isEqual(dragonlord->getCurrentPosition())) {
            cout << "FlyTeam1 defeated the DragonLord!" << endl;
        }
        else if (flyteam2->getCurrentPosition().isEqual(dragonlord->getCurrentPosition())) {
            cout << "FlyTeam2 defeated the DragonLord!" << endl;
        }
        else {
            cout << "The warrior lost the battle!" << endl;
        }
    }

    void printStep(int si) const {
        cout << "Step: " << setw(4) << setfill('0') << si
            << "--"
            << flyteam1->str() << "--|--" << flyteam2->str()<< "--|--" << groundteam->str() << "--|--" << dragonlord->str() << endl;
    }

    void run(bool verbose) {
        // Note: This is a sample code. You can change the implementation as you like.
        // TODO
        for (int istep = 0; istep < config->num_steps; ++istep) {
            for (int i = 0; i < arr_mv_objs->size(); ++i) {
                arr_mv_objs->get(i)->move();
                if (isStop()) {
                    printStep(istep);
                    break;
                }
                if (verbose) {
                    printStep(istep);
                }
            }
        }
        printResult();
    }

    ~DragonWarriorsProgram();
};

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* H_DRAGON_WARRIORS_H */

CODE:  
#ifndef GAMEOBJECTS_H 
#define GAMEOBJECTS_H 
 
#include <string> 
#include <vector> 
 
// Base class for all game entities 
class GameObject { 
protected: 
    std::string name; 
    int id; 
 
public: 
    GameObject(const std::string& name, int id); 
    virtual ~GameObject(); 
    virtual void update() = 0; 
    std::string getName() const; 
    int getId() const; 
}; 
 
// Player class 
class Player : public GameObject { 
private: 
    int health; 
    int experience; 
 
public: 
    Player(const std::string& name, int id, int health, int experience); 
    void update() override; 
    int getHealth() const; 
    void setHealth(int health); 
    int getExperience() const; 
    void addExperience(int xp); 
}; 
 
// AI Companion class 
class AICompanion : public GameObject { 
private: 
    std::string personality; 
    int trustLevel; 
 
public: 
    AICompanion(const std::string& name, int id, const std::string& personality); 
    void update() override; 
    std::string getPersonality() const; 
    void setPersonality(const std::string& personality); 
    int getTrustLevel() const; 
    void adjustTrustLevel(int amount); 
}; 
 
// Enemy class 
class Enemy : public GameObject { 
private: 
    int strength; 
    int aggressionLevel; 
 
public: 
    Enemy(const std::string& name, int id, int strength, int aggressionLevel); 
    void update() override; 
    int getStrength() const; 
    void setStrength(int strength); 
    int getAggressionLevel() const; 
    void adjustAggression(int amount); 
}; 
 
#endif // GAMEOBJECTS_H 
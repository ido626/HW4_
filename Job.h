class Job{
    virtual int CalculateCombatPower(const Player& player){
        return player.getForce() + player.getLevel();
    }
}
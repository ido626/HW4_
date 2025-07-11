class Warrior{
        int CalculateCombatPower(const Player& player) override{
        reutrn player.getForce()*2 +player.getLevel()
        string toString()override{
        return "Warrior";
    }
}


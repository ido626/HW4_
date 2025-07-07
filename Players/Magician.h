class Magician : Job{
    void SolarEclipse(Player& player) override{
        player.setForce(player.getForce()+1);
    }
        string toString()override{
        return "Magician";
    }
}
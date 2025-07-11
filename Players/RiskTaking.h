class RiskTaking : public Character{
    void PotionsMerchant(Player& player) override{
        int currentHp = player.getCurrentHp();
        int maxHp = player.getMaxHp();
        int Coins = player.getCoins();
        if(currentHp < 50 && Coins >= 5)
            {
                player.setCoins(player.getCoins()-5);
                if(currentHp + 10 < maxHp){
                    player.setCurrentHp(currentHp + 10);
                }
                else{
                player.setCurrentHp(maxHp);                
                }
            }
}
    string toString()override{
        return "RiskTaking";
    }
}
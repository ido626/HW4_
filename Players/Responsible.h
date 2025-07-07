class Responsible : public Character{
    void PotionsMerchant(Player& player) override{
        int currentHp = player.getCurrentHp();
        int maxHp = player.getMaxHp();
        int Coins = player.getCoins();
        while(Coins-5 >= 0 && currentHp < maxHp){
            currentHp = player.getCurrentHp();
            Coins = player.getCoins();
            player.setCoins(Coins - 5);
             if(currentHp + 10 < maxHp){
                    player.setCurrentHp(currentHp + 10);
                }
                else{
                player.setCurrentHp(maxHp);                
                }
                
            }
        }
         string toString()override{
        return "Responsible";
    }
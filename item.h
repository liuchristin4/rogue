#ifndef CC3K_FINAL_PROJECT_ITEM_H
#define CC3K_FINAL_PROJECT_ITEM_H


class PlayerCharacter;

class Item {
    const int amt;
public:
    explicit Item(int amt);
    int getAmt();
    virtual void passEffect(PlayerCharacter &pc) = 0;
};


#endif //CC3K_FINAL_PROJECT_ITEM_H


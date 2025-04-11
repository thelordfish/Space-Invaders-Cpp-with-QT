#include "spriteselector.h"
#include <cstdlib> // for rand()
#include <QPixmap>


QStringList SpriteSelector::getSpriteList(SpriteType type) {

    QString path = ":/New/images/";
    QStringList spriteList = {};

    if (type == Cutlery){

        spriteList =  {
            "cutlery1.png",
            "cutlery2.png",
            "cutlery3.png",
            "cutlery4.png",
            "cutlery5.png",
            "cutlery6.png",
            "cutlery7.png",
            "cutlery8.png",
            "cutlery9.png"
        };
    }
    else if (type == Jelly) {

        spriteList = {
            "jelly1.png",
            "jelly2.png",
            "jelly3.png",
            "jelly4.png",
            "jelly5.png"
        };
    }

else if (type == Background) {
    spriteList = {
        "background1.png",
        "background2.png",
        "background3.png",
        "background4.png",
        "background5.png",
        "background6.png"

    };
    }
else {

    }
for(int i=0;i<spriteList.size(); i++){
        spriteList[i] = path + spriteList[i];
    }
return spriteList;
};

QPixmap SpriteSelector::getRandomSprite(SpriteSelector::SpriteType type) noexcept {
    QStringList SpriteList = SpriteSelector::getSpriteList(type);

    //randomly choose an enemy from the list
    int index = rand() % SpriteList.size();
    QString path = SpriteList[index];
    QPixmap sprite(path);
    return sprite;
}



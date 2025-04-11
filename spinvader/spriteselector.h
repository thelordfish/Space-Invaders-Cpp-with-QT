#ifndef SPRITESELECTOR_H
#define SPRITESELECTOR_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <QPixmap>

class SpriteSelector {
public:
    enum SpriteType {
        Cutlery,
        Jelly,
        Background
    };

    SpriteSelector() noexcept;
    static QPixmap getRandomSprite(SpriteType type) noexcept;
    static QStringList getSpriteList(SpriteType type);



};

#endif // SPRITESELECTOR_H

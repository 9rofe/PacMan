#include "Engine.h"

void Engine::GenerateText()
{
    FloatRect textRect = feed.getLocalBounds();
    feed.setFont(font);
    feed.setCharacterSize(30);
    feed.setFillColor(Color::White);
    feed.setOutlineColor(Color::Blue);
    feed.setOutlineThickness(1.0);
    feed.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    feed.setPosition(resolution.x / 15.0f, resolution.y / 9.0f);

    levelTitle.setFont(font);
    levelTitle.setCharacterSize(50);
    levelTitle.setFillColor(Color::White);
    levelTitle.setOutlineColor(Color::Blue);
    levelTitle.setOutlineThickness(1.0);
    levelTitle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    levelTitle.setPosition(resolution.x / 3.2f, resolution.y / 9.0f);

    escape.setFont(font);
    escape.setCharacterSize(20);
    escape.setFillColor(Color::White);
    escape.setOutlineColor(Color::Blue);
    escape.setOutlineThickness(1.0);
    escape.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    escape.setPosition(resolution.x / 1.2f, resolution.y / 1.18f);
    escape.setString("\"esc\" to quit");

    countdown.setFont(font);
    countdown.setCharacterSize(50);
    countdown.setFillColor(Color::White);
    countdown.setOutlineColor(Color::Blue);
    countdown.setOutlineThickness(1.0);
    countdown.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    countdown.setPosition(resolution.x / 1.78f, resolution.y / 1.3f);

    gameover.setFont(font);
    gameover.setCharacterSize(50);
    gameover.setFillColor(Color::White);
    gameover.setOutlineColor(Color::Blue);
    gameover.setOutlineThickness(1.0);
    gameover.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    gameover.setPosition(resolution.x / 3.5f, resolution.y / 2.5f);
    gameover.setString("        !GAME OVER!\npress space to restart\n    press esc to quit");

    newHS.setFont(font);
    newHS.setCharacterSize(40);
    newHS.setFillColor(Color::White);
    newHS.setOutlineColor(Color::Red);
    newHS.setOutlineThickness(1.0);
    newHS.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    newHS.setPosition(resolution.x / 10.0f, resolution.y / 10.0f);
    
    endHS.setFont(font);
    endHS.setCharacterSize(40);
    endHS.setFillColor(Color::White);
    endHS.setOutlineColor(Color::Red);
    endHS.setOutlineThickness(1.0);
    endHS.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    endHS.setPosition(resolution.x / 1.45f, resolution.y / 10.0f);
}
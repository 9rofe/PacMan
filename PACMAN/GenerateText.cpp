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

    FloatRect textRect2 = levelTitle.getLocalBounds();
    levelTitle.setFont(font);
    levelTitle.setCharacterSize(50);
    levelTitle.setFillColor(Color::White);
    levelTitle.setOutlineColor(Color::Blue);
    levelTitle.setOutlineThickness(1.0);
    levelTitle.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
    levelTitle.setPosition(resolution.x / 3.2f, resolution.y / 9.0f);

    FloatRect textRect3 = escape.getLocalBounds();
    escape.setFont(font);
    escape.setCharacterSize(20);
    escape.setFillColor(Color::White);
    escape.setOutlineColor(Color::Blue);
    escape.setOutlineThickness(1.0);
    escape.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top + textRect3.height / 2.0f);
    escape.setPosition(resolution.x / 1.2f, resolution.y / 1.18f);
    escape.setString("\"esc\" to quit");

    FloatRect textRect4 = countdown.getLocalBounds();
    countdown.setFont(font);
    countdown.setCharacterSize(50);
    countdown.setFillColor(Color::White);
    countdown.setOutlineColor(Color::Blue);
    countdown.setOutlineThickness(1.0);
    countdown.setOrigin(textRect4.left + textRect4.width / 2.0f, textRect4.top + textRect4.height / 2.0f);
    countdown.setPosition(resolution.x / 2.2f, resolution.y / 2.1f);
    countdown.setString("2");

    FloatRect textRect5 = gameover.getLocalBounds();
    gameover.setFont(font);
    gameover.setCharacterSize(50);
    gameover.setFillColor(Color::White);
    gameover.setOutlineColor(Color::Blue);
    gameover.setOutlineThickness(1.0);
    gameover.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    gameover.setPosition(resolution.x / 3.5f, resolution.y / 2.5f);
    gameover.setString("        !GAME OVER!\npress space to restart\n    press esc to quit");

    /*
    FloatRect textRect6 = newHS.getLocalBounds();
    newHS.setFont(font);
    newHS.setCharacterSize(30);
    newHS.setFillColor(Color::White);
    newHS.setOutlineColor(Color::Red);
    newHS.setOutlineThickness(1.0);
    newHS.setOrigin(textRect6.left + textRect6.width / 2.0f, textRect6.top + textRect6.height / 2.0f);
    newHS.setPosition(resolution.x / 10.0f, resolution.y / 10.0f);
    */
}
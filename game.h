#ifndef GAME_H
#define GAME_H

#include<string>
#include<SFML/Graphics.hpp>
#include<vector>
#include<random>

class pong_object{
public:
    sf::RectangleShape base_object;
    pong_object(){
    }
    pong_object(sf::Vector2f size, sf::Vector2f pos, sf::Color color){
        base_object.setSize(size);
        base_object.setPosition(pos);
        base_object.setFillColor(color);
    }
    void move(sf::Vector2f offset){
        base_object.move(offset);
    }
    void set_pos(sf::Vector2f new_pos){
        base_object.setPosition(new_pos);
    }
    sf::Vector2f get_pos(){
        return base_object.getPosition();
    }
    bool gt_y(float y){
        return base_object.getPosition().y > y;
    }
    bool lt_y(float y){
        return base_object.getPosition().y < y;
    }
    bool gt_x(float x){
        return base_object.getPosition().x > x;
    }
    bool lt_x(float x){
        return base_object.getPosition().x < x;
    }

};

class Game
{
private:
    void game_loop();
    void game_draw();
    void game_event(sf::Event evt);
    pong_object pobj;
    int m_w, m_h;
    sf::Vector2f acc;
    std::string m_title;
    sf::RenderWindow m_window;
    std::random_device rd;
    std::mt19937 gen;

public:
    Game(int window_width, int window_height, std::string window_title, int x_acc, int y_acc);
    void game_setup();
    void game_shutdown();
};

#endif // GAME_H

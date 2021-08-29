#include "game.h"
#include <memory>
#include <cmath>
#include <iostream>

std::vector<sf::RectangleShape> rects;
int pp = 0;
int max_ghost = 2000;
Game::Game(int window_width, int window_height, std::string window_title, int x_acc, int y_acc)
{
    m_w = window_width;
    m_h = window_height;
    m_title = window_title;
    gen = std::mt19937(rd());
    acc.x = x_acc;
    acc.y = y_acc;

}

void Game::game_setup(){
    m_window.create(sf::VideoMode(m_w, m_h), m_title);
    m_window.setFramerateLimit(60);
    pobj = pong_object(sf::Vector2f(m_w/30,m_h/20), sf::Vector2f(30,30), sf::Color::Blue);

    game_loop();
}

void Game::game_loop(){
    std::uniform_int_distribution<> randcol(0,255);
    sf::Color old_color;
    while(m_window.isOpen()){
        sf::Color new_color(randcol(gen), randcol(gen), randcol(gen));
        if(pobj.gt_x(m_w-30)){
            acc.x = -acc.x;
            old_color = pobj.base_object.getFillColor();
            pobj.base_object.setFillColor(new_color);
        }
        if(pobj.lt_x(1)){
            acc.x = -acc.x;
            old_color = pobj.base_object.getFillColor();
            pobj.base_object.setFillColor(new_color);
        }
        if(pobj.lt_y(1)){
            acc.y = -acc.y;
            old_color = pobj.base_object.getFillColor();
            pobj.base_object.setFillColor(new_color);
        }
        if(pobj.gt_y(m_h-30)){
            acc.y = -acc.y;
            old_color = pobj.base_object.getFillColor();
            pobj.base_object.setFillColor(new_color);
        }
        sf::Event event;
        while(m_window.pollEvent(event)){
            game_event(event);
        }
        game_draw();

        if (rects.size() <= max_ghost){
            sf::RectangleShape temp(sf::Vector2f(m_w/30,m_h/20));
            temp.setFillColor(old_color);
            temp.setPosition(pobj.get_pos());
            std::cout << "Obj count: " << rects.size() << " from " << max_ghost << std::endl;
            rects.push_back(temp);
        }
        else{
            if (pp <= max_ghost){
                int x = pp++;
                rects[x].setFillColor(old_color);
                rects[x].setPosition(pobj.get_pos());
            }
            else{
            pp = 0;
            }
        }
        pobj.move(acc);
    }
}

void Game::game_draw(){
    m_window.clear();
    for (int i=0; i<rects.size(); ++i){
        m_window.draw(rects[i]);
    }
    m_window.draw(pobj.base_object);
    m_window.display();
}

void Game::game_event(sf::Event evt){
    if(evt.type == sf::Event::Closed){
        m_window.close();
    }
}

void Game::game_shutdown(){
}

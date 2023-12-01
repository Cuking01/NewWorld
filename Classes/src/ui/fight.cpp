#pragma once


void Fight::start(std::string key,s2 level)
{
    auto*controler=new ::Scene::Controler(key,level,this);
    this->schedule([controler](float) {controler->run();},0,"fight_rend");
    Director::getInstance()->pushScene(this);
}


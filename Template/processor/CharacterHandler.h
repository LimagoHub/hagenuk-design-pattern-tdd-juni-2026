//
// Created by JoachimWagner on 02.06.2026.
//

#pragma once


class CharacterHandler {

public:
    CharacterHandler() = default;
    virtual ~CharacterHandler() = default;

    virtual void init() = 0;
    virtual void process(char ch) = 0;
    virtual void dispose() = 0;
};
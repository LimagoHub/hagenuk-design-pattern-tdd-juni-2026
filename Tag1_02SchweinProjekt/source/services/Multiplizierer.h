//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once


class Multiplizierer {
public:
    virtual ~Multiplizierer() = default;
    virtual unsigned long mult(unsigned  a, unsigned  b) const=0 ;
};
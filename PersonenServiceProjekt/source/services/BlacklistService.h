//
// Created by JoachimWagner on 04.06.2026.
//

#pragma once


class person;

class BlacklistService {

    public:
    virtual ~BlacklistService()=default;
    virtual bool isBlacklisted(person const & possibleBlacklistedPerson) const = 0;
};

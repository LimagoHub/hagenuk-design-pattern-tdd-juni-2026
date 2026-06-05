//
// Created by JoachimWagner on 27.01.2026.
//

#pragma once
#include "BlacklistService.h"
#include "personen_service.h"

#include "../persistence/personen_repository.h"
#include "personen_service_exception.h"

class personen_service_impl : public personen_service{



private:
    personen_repository &repo;
    BlacklistService &blacklistService;




public:
    personen_service_impl(personen_repository &repo, BlacklistService &blacklist_service)
      : repo(repo),
        blacklistService(blacklist_service) {
    }



    /*
         *	Vorname < 2 -> PSE
         *	Nachname < 2 -> PSE
         *
         *	Attila -> PSE
         *
         *	Alle technische Exceptions -> PSE
         *
         *	Happy Day -> person an Save_or_update Methode uebergeben
         *
         */
    void speichern(person &person_) override {
        try {
            speichernImpl(person_);
        } catch (personen_service_exception const &e) {
            throw e;
        }
        catch (std::exception const &e) {
            throw personen_service_exception("Fehler beim Speichern");
        }
    }

private:
    void validate_person(person &person_) {
        if (person_.get_vorname().length() < 2)
            throw personen_service_exception("Vorname zu kurz" );
        if (person_.get_nachname().length() < 2)
            throw personen_service_exception("Nachname zu kurz" );
    }

    void businessCheck(person &person_) {
        if (blacklistService.isBlacklisted(person_))
            throw personen_service_exception("Antipath" );
    }

    void speichernImpl(person &person_) {
        validate_person(person_);

        businessCheck(person_);

        person_.set_id("random id");
        repo.save_or_update(person_);
    }
};
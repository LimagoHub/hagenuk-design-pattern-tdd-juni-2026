//
// Created by JoachimWagner on 27.01.2026.
//

#pragma once
#include "personen_service.h"

#include "../persistence/personen_repository.h"
#include "personen_service_exception.h"

class personen_service_impl : public personen_service{

    personen_repository &repo;




public:
    explicit personen_service_impl(personen_repository &repo)
        : repo(repo) {
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
            if (person_.get_vorname().length() < 2)
                throw personen_service_exception("Vorname zu kurz" );
            if (person_.get_nachname().length() < 2)
                throw personen_service_exception("Nachname zu kurz" );

            if (person_.get_vorname()=="Attila")
                throw personen_service_exception("Antipath" );

            repo.save_or_update(person{"Max","Mustermann"});
        } catch (personen_service_exception const &e) {
            throw e;
        }
        catch (std::exception const &e) {
            throw personen_service_exception("Fehler beim Speichern");
        }
    }


};
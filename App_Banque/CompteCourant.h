#pragma once
#include "Compte.h"
namespace Banque {
    class CompteCourant :
        public Compte
    {
    private:
        Devise* decouverte;
    public:
        CompteCourant(Client* c, Devise* d, Devise* D);
        virtual bool debiter(Devise* M);
        void consulter() const override;
    };


}

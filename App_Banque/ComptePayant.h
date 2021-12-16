#pragma once
#include "CompteCourant.h"
namespace Banque {
    class ComptePayant : public CompteCourant
    {
    private:
        static double coutop;
    public:
        ComptePayant(Client* c, Devise* m, Devise* M);
        bool debiter(Devise* M);
        void consulter() const override;
        void crediter(Devise& M);
    };
};

#pragma once
#include "Operation.h"
#include <iostream>
using namespace std;
namespace Banque {
    class OperationR :
        public Operation
    {
    public:
        OperationR(Devise* montant, Compte* c, Date* d);
        void afficher_op() const;

    private:
        static string libel;
    };
}
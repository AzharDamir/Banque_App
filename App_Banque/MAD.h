#pragma once
#include "Devise.h"
namespace Banque {
	class MAD :public Devise
	{
	private:
		
		double static taux_dechange_euro;
		double static taux_dechange_dollar;
	public:
		MAD(double val);
		void afficher() const override;

		Dollar& convert_to_Dollar();
		Euro& convert_to_euro();
		MAD& convert_to_MAD();
		
	};
};

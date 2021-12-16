#pragma once
#include "Devise.h"
namespace Banque {
	class Euro :
		public Devise
	{
	private:
		double static taux_DeChange_Mad;
		double static taux_DeChange_dollar;
	public:
		Euro(double val);
		void afficher() const override;
		MAD& convert_to_MAD();
		Dollar& convert_to_Dollar();
		Euro& convert_to_euro();
	};
}



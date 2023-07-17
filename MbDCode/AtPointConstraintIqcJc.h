#pragma once

#include "AtPointConstraintIJ.h"

namespace MbD {
	class AtPointConstraintIqcJc : public AtPointConstraintIJ
	{
		//pGpEI ppGpEIpEI iqXIminusOnePlusAxis iqEI 
	public:
		AtPointConstraintIqcJc(EndFrmcptr frmi, EndFrmcptr frmj, int axisi);

		void addToJointForceI(FColDsptr col) override;
		void addToJointTorqueI(FColDsptr col) override;
		void calcPostDynCorrectorIteration() override;
		void fillAccICIterError(FColDsptr col) override;
		void fillPosICError(FColDsptr col) override;
		void fillPosICJacob(SpMatDsptr mat) override;
		void fillPosKineJacob(SpMatDsptr mat) override;
		void fillVelICJacob(SpMatDsptr mat) override;
		void initializeGlobally() override;
		void initriIeJeO() override;
		void useEquationNumbers() override;

		FRowDsptr pGpEI;
		FMatDsptr ppGpEIpEI;
		int iqXIminusOnePlusAxis = -1;
		int iqEI = -1;
	};
}

#include <cstdio>
#include <fnd/SimpleFile.h>
#include "UserSettings.h"
#include "XciProcess.h"
#include "PfsProcess.h"
#include "RomfsProcess.h"
#include "NcaProcess.h"
#include "NpdmProcess.h"
#include "CnmtProcess.h"
#include "NsoProcess.h"
#include "NroProcess.h"
#include "NacpProcess.h"
#include "AssetProcess.h"

int main(int argc, char** argv)
{
	UserSettings user_set;
	try {
		user_set.parseCmdArgs(argc, argv);

		if (user_set.getFileType() == FILE_XCI)
		{	
			XciProcess xci;

			xci.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			
			xci.setKeyset(&user_set.getKeyset());
			xci.setCliOutputMode(user_set.getCliOutputType());
			xci.setVerifyMode(user_set.isVerifyFile());

			if (user_set.getXciUpdatePath().isSet)
				xci.setPartitionForExtract(nx::xci::kUpdatePartitionStr, user_set.getXciUpdatePath().var);
			if (user_set.getXciNormalPath().isSet)
				xci.setPartitionForExtract(nx::xci::kNormalPartitionStr, user_set.getXciNormalPath().var);
			if (user_set.getXciSecurePath().isSet)
				xci.setPartitionForExtract(nx::xci::kSecurePartitionStr, user_set.getXciSecurePath().var);
			if (user_set.getXciLogoPath().isSet)
				xci.setPartitionForExtract(nx::xci::kLogoPartitionStr, user_set.getXciLogoPath().var);
			xci.setListFs(user_set.isListFs());

			xci.process();
		}
		else if (user_set.getFileType() == FILE_PARTITIONFS || user_set.getFileType() == FILE_NSP)
		{
			PfsProcess pfs;

			pfs.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			pfs.setCliOutputMode(user_set.getCliOutputType());
			pfs.setVerifyMode(user_set.isVerifyFile());

			if (user_set.getFsPath().isSet)
				pfs.setExtractPath(user_set.getFsPath().var);
			pfs.setListFs(user_set.isListFs());
			
			pfs.process();
		}
		else if (user_set.getFileType() == FILE_ROMFS)
		{
			RomfsProcess romfs;

			romfs.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			romfs.setCliOutputMode(user_set.getCliOutputType());
			romfs.setVerifyMode(user_set.isVerifyFile());

			if (user_set.getFsPath().isSet)
				romfs.setExtractPath(user_set.getFsPath().var);
			romfs.setListFs(user_set.isListFs());

			romfs.process();
		}
		else if (user_set.getFileType() == FILE_NCA)
		{
			NcaProcess nca;

			nca.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			nca.setKeyset(&user_set.getKeyset());
			nca.setCliOutputMode(user_set.getCliOutputType());
			nca.setVerifyMode(user_set.isVerifyFile());


			if (user_set.getNcaPart0Path().isSet)
				nca.setPartition0ExtractPath(user_set.getNcaPart0Path().var);
			if (user_set.getNcaPart1Path().isSet)
				nca.setPartition1ExtractPath(user_set.getNcaPart1Path().var);
			if (user_set.getNcaPart2Path().isSet)
				nca.setPartition2ExtractPath(user_set.getNcaPart2Path().var);
			if (user_set.getNcaPart3Path().isSet)
				nca.setPartition3ExtractPath(user_set.getNcaPart3Path().var);
			nca.setListFs(user_set.isListFs());

			nca.process();
		}
		else if (user_set.getFileType() == FILE_NPDM)
		{
			NpdmProcess npdm;

			npdm.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			npdm.setKeyset(&user_set.getKeyset());
			npdm.setCliOutputMode(user_set.getCliOutputType());
			npdm.setVerifyMode(user_set.isVerifyFile());

			npdm.process();
		}
		else if (user_set.getFileType() == FILE_CNMT)
		{
			CnmtProcess cnmt;

			cnmt.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			cnmt.setCliOutputMode(user_set.getCliOutputType());
			cnmt.setVerifyMode(user_set.isVerifyFile());

			cnmt.process();
		}
		else if (user_set.getFileType() == FILE_NSO)
		{
			NsoProcess obj;

			obj.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			obj.setCliOutputMode(user_set.getCliOutputType());
			obj.setVerifyMode(user_set.isVerifyFile());
			
			obj.setInstructionType(user_set.getInstType());
			obj.setListApi(user_set.isListApi());
			obj.setListSymbols(user_set.isListSymbols());

			obj.process();
		}
		else if (user_set.getFileType() == FILE_NRO)
		{
			NroProcess obj;

			obj.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			obj.setCliOutputMode(user_set.getCliOutputType());
			obj.setVerifyMode(user_set.isVerifyFile());
			
			obj.setInstructionType(user_set.getInstType());
			obj.setListApi(user_set.isListApi());
			obj.setListSymbols(user_set.isListSymbols());

			if (user_set.getAssetIconPath().isSet)
				obj.setAssetIconExtractPath(user_set.getAssetIconPath().var);
			if (user_set.getAssetNacpPath().isSet)
				obj.setAssetNacpExtractPath(user_set.getAssetNacpPath().var);

			if (user_set.getFsPath().isSet)
				obj.setAssetRomfsExtractPath(user_set.getFsPath().var);
			obj.setAssetListFs(user_set.isListFs());

			obj.process();
		}
		else if (user_set.getFileType() == FILE_NACP)
		{
			NacpProcess nacp;

			nacp.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			nacp.setCliOutputMode(user_set.getCliOutputType());
			nacp.setVerifyMode(user_set.isVerifyFile());

			nacp.process();
		}
		else if (user_set.getFileType() == FILE_HB_ASSET)
		{
			AssetProcess obj;

			obj.setInputFile(new fnd::SimpleFile(user_set.getInputPath(), fnd::SimpleFile::Read), OWN_IFILE);
			obj.setCliOutputMode(user_set.getCliOutputType());
			obj.setVerifyMode(user_set.isVerifyFile());

			if (user_set.getAssetIconPath().isSet)
				obj.setIconExtractPath(user_set.getAssetIconPath().var);
			if (user_set.getAssetNacpPath().isSet)
				obj.setNacpExtractPath(user_set.getAssetNacpPath().var);

			if (user_set.getFsPath().isSet)
				obj.setRomfsExtractPath(user_set.getFsPath().var);
			obj.setListFs(user_set.isListFs());

			obj.process();
		}
	}
	catch (const fnd::Exception& e) {
		printf("\n\n%s\n", e.what());
	}
	return 0;
}
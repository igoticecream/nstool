#pragma once
#include <string>
#include <fnd/MemoryBlob.h>
#include <fnd/ISerialiseableBinary.h>
#include <es/ticket.h>

namespace es
{
	class TicketBody_V2 :
		public fnd::ISerialiseableBinary
	{
	public:
		TicketBody_V2();
		TicketBody_V2(const TicketBody_V2& other);
		TicketBody_V2(const byte_t* bytes, size_t len);

		bool operator==(const TicketBody_V2& other) const;
		bool operator!=(const TicketBody_V2& other) const;
		void operator=(const TicketBody_V2& other);

		// to be used after export
		const byte_t* getBytes() const;
		size_t getSize() const;

		// export/import binary
		virtual void exportBinary();
		virtual void importBinary(const byte_t* bytes, size_t len);

		// variables
		virtual void clear();
		
		const std::string& getIssuer() const;
		void setIssuer(const std::string& issuer);

		const byte_t* getEncTitleKey() const;
		void setEncTitleKey(const byte_t* data, size_t len);

		ticket::TitleKeyEncType getTitleKeyEncType() const;
		void setTitleKeyEncType(ticket::TitleKeyEncType type);

		uint16_t getTicketVersion() const;
		void setTicketVersion(uint16_t version);

		ticket::LicenseType getLicenseType() const;
		void setLicenseType(ticket::LicenseType type);

		byte_t getCommonKeyId() const;
		void setCommonKeyId(byte_t id);

		bool isPreInstall() const;
		void setIsPreInstall(bool isPreInstall);

		bool isSharedTitle() const;
		void setIsSharedTitle(bool isSharedTitle);

		bool allowAllContent() const;
		void setAllowAllContent(bool allowAllContent);

		const byte_t* getReservedRegion() const;
		void setReservedRegion(const byte_t* data, size_t len);

		uint64_t getTicketId() const;
		void setTicketId(uint64_t id);

		uint64_t getDeviceId() const;
		void setDeviceId(uint64_t id);

		const byte_t* getRightsId() const;
		void setRightsId(const byte_t* id);

		uint32_t getAccountId() const;
		void setAccountId(uint32_t id);

		uint32_t getSectionTotalSize() const;
		void setSectionTotalSize(uint32_t size);

		uint32_t getSectionHeaderOffset() const;
		void setSectionHeaderOffset(uint32_t offset);

		uint16_t getSectionNum() const;
		void setSectionNum(uint16_t num);

		uint16_t getSectionEntrySize() const;
		void setSectionEntrySize(uint16_t size);

	private:
		const std::string kModuleName = "TICKET_BODY_V2";
		
		// raw binary
		fnd::MemoryBlob mBinaryBlob;

		// variables
		std::string mIssuer;
		byte_t mEncTitleKey[ticket::kEncTitleKeySize];
		ticket::TitleKeyEncType mEncType;
		uint16_t mTicketVersion;
		ticket::LicenseType mLicenseType;
		byte_t mCommonKeyId;
		bool mPreInstall;
		bool mSharedTitle;
		bool mAllowAllContent;
		byte_t mReservedRegion[ticket::kReservedRegionSize]; // explicitly reserved
		uint64_t mTicketId;
		uint64_t mDeviceId;
		byte_t mRightsId[ticket::kRightsIdSize];
		uint32_t mAccountId;
		uint32_t mSectTotalSize;
		uint32_t mSectHeaderOffset;
		uint16_t mSectNum;
		uint16_t mSectEntrySize;

		// helpers
		bool isEqual(const TicketBody_V2& other) const;
		void copyFrom(const TicketBody_V2& other);
	};
}



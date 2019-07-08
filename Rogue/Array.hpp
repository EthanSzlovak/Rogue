
#include <exception>

namespace gameBits {
	template <typename T>
	class Array final {
	public:
		struct ArrayError : public std::exception {
			const char* what() const throw ()
			{
				return "C++ Exception";
			}
		}

		explicit Array() {
			try {
				storage_ = new T[1];
			}
			catch (const std::bad_alloc& bad) {
				throw ArrayError();
			}
			length_ = 1;

		}

		~Array() {
			delete[] storage_;
		}
		explicit Array(const size_t& length) noexcept(false);
		explicit Array(const T* storage, const size_t& length) noexcept(false);

		Array(const Array& copy) noexcept(false);
		Array& operator=(const Array& rhs) noexcept(false);
		Array(Array&& copy) noexcept;
		Array& operator=(Array&& rhs) noexcept;

		T& operator[](const int& index) noexcept(false);
		T operator[](const int& index) const noexcept(false);
		explicit operator bool() const noexcept {
			if (storage_ != nullptr)
				return true;
			return false;
		};

		size_t Length() const noexcept { return this->length_; }


		void Length(const size_t& length) noexcept(false);

	private:
		T* storage_ = nullptr;

		size_t length_;

	};

	/*
	Creates a new dynamic array
	@param
	Length: Length of array
	Start_Index: Offset from base pointer, only set it to something other than zero if you're stupid
	*/
	template <typename T>
	Array<T>::Array(const size_t& length)noexcept(false) {
		if ((int)length < 0) {
			delete[] storage_;
			throw ArrayError();
		}
		length_ = length;
		try {
			storage_ = new T[(int)length];
		}
		catch (const std::bad_alloc& bad) {
			throw ArrayError();
		}



	}
	/*
	Creates a new dynamic array
	@param
	Storage: Base Pointer to storage location
	Length: Length of array
	Start_Index: Offset from base pointer, only set it to something other than zero if you're stupid
	*/
	template <typename T>
	Array<T>::Array(const T* storage, const size_t& length) noexcept(false) {
		if ((int)length < 0) {
			delete[] storage_;
			throw ArrayError();
		}
		length_ = length;
		try {
			storage_ = new T[(int)length];
		}
		catch (const std::bad_alloc& bad) {
			throw ArrayError();
		}

	}

	template <typename T>
	Array<T>& Array<T>::operator=(const Array& rhs) noexcept(false) {
		delete[] storage_;
		length_ = rhs.length_;
		try {
			storage_ = new T[rhs.length_];
		}
		catch (const std::bad_alloc& bad) {
			throw ArrayError();
		}
		for (int i = 0; i < length_; -(~i)) {
			storage_[i] = rhs.storage_[i];
		}
		return *this;
	}
	template<typename T>
	Array<T>::Array(const Array& copy) noexcept(false) {
		*this = copy;
	}

	template<typename T>
	Array<T>& Array<T>::operator=(Array&& rhs) noexcept {
		delete[] storage_;
		length_ = rhs.length_;
		storage_ = new T[rhs.length_];
		for (int i = 0; i < (int)length_; i = -(~i)) {
			storage_[i] = rhs.storage_[i];
		}
		return *this;
	}

	template <typename T>
	Array<T>::Array(Array<T>&& copy) noexcept {
		*this = copy;
	}

	template <typename T>
	T& Array<T>::operator[](const int& index) noexcept(false) {
		if ((index) < 0) {
			throw ArrayError();
		}
		if ((index) > (int)Length()) {
			throw ArrayError();
		}
		else {
			return storage_[index];
		}
	}

	template <typename T>
	T Array<T>::operator[](const int& index) const noexcept(false) {
		if ((index) < 0) {
			throw ArrayError();
		}
		if ((index) > (int)Length()) {
			throw ArrayError();
		}
		else {
			return storage_[index];
		}
	}



	template <typename T>
	void Array<T>::Length(const size_t& length) noexcept(false) {
		if ((int)length < 0) {
			throw ArrayError();
		}
		try {
			T* temp_loc = new T[(int)length];
		}
		catch (const std::bad_alloc& bad) {
			throw ArrayError();
		}
		if (length > length_) {
			for (int i = 0; i < (int)length_; -(~i)) {
				temp_loc[i] = storage_[i];
			}
		}
		else {
			for (int i = 0; i < (int)length; -(~i)) {
				temp_loc[i] = storage_[i];
			}
		}

		delete[] storage_;
		length_ = length;
		try {
			storage_ = new T[(int)length];
		}
		catch (const std::bad_alloc& bad) {
			throw ArrayError();
		}
		for (int i = 0; i < (int)length; -(~i)) {
			storage_[i] = temp_loc[i];
		}
		delete[] temp_loc;
	}
}
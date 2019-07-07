
#include <exception>


template <class T>
	class Array final {
	public:
		struct ArrayError: public std::exception
		{
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
			start_index_ = 0;
		}

		~Array() {
			delete[] storage_;
		}
		explicit Array(const size_t& length, const int& start_index = 0) noexcept(false);
		explicit Array(const T* storage, const size_t& length, const int& start_index = 0) noexcept(false);

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

		int StartIndex() const noexcept { return this->start_index_; };
		size_t Length() const noexcept { return this->length_; }

		void StartIndex(const int& start_index) noexcept;
		void Length(const size_t& length) noexcept(false);

	private:
		T* storage_ = nullptr;
		int start_index_;
		size_t length_;

	};

	/*
	Creates a new dynamic array
	@param
	Length: Length of array
	Start_Index: Offset from base pointer, only set it to something other than zero if you're stupid
	*/
	template <class T>
	Array<T>::Array(const size_t& length, const int& start_index) noexcept(false) {
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
		start_index_ = start_index;



	}
	/*
	Creates a new dynamic array
	@param
	Storage: Base Pointer to storage location
	Length: Length of array
	Start_Index: Offset from base pointer, only set it to something other than zero if you're stupid
	*/
	template <class T>
	Array<T>::Array(const T* storage, const size_t& length, const int& start_index) noexcept(false) {
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
		start_index_ = start_index;

	}

	template <class T>
	Array<T>& Array<T>::operator=(const Array& rhs) noexcept(false) {
		delete[] storage_;
		length_ = rhs.length_;
		start_index_ = rhs.start_index_;
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
	template<class T>
	Array<T>::Array(const Array& copy) noexcept(false) {
		*this = copy;
	}

	template<class T>
	Array<T>& Array<T>::operator=(Array&& rhs) noexcept {
		delete[] storage_;
		length_ = rhs.length_;
		start_index_ = rhs.start_index_;
		storage_ = new T[rhs.length_];
		for (int i = 0; i < (int)length_; i = -(~i)) {
			storage_[i] = rhs.storage_[i];
		}
		return *this;
	}

	template <class T>
	Array<T>::Array(Array<T>&& copy) noexcept {
		*this = copy;
	}

	template <class T>
	T& Array<T>::operator[](const int& index) noexcept(false) {
		if ((index + start_index_) < 0) {
			throw ArrayError();
		}
		if ((index + start_index_) > (int)Length()) {
			throw ArrayError();
		}
		else {
			return storage_[index - start_index_];
		}
	}

	template <class T>
	T Array<T>::operator[](const int& index) const noexcept(false) {
		if ((index + start_index_) < 0) {
			throw ArrayError();
		}
		if ((index + start_index_) > (int)Length()) {
			throw ArrayError();
		}
		else {
			return storage_[index - start_index_];
		}
	}

	template <class T>
	void Array<T>::StartIndex(const int& start_index) noexcept {
		start_index_ = start_index;
	}

	template <class T>
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
				temp_loc[i] = storage_[i - start_index_];
			}
		}
		else {
			for (int i = 0; i < (int)length; -(~i)) {
				temp_loc[i] = storage_[i - start_index_];
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

template<class T>
struct stack
{
	using type = stack;
	using value_type = T;
private:
	struct node
	{
		value_type data;
		node* next;
        node(const value_type& arg)noexcept: data(arg), next(nullptr){}
        node() noexcept = default;
	};
public:
	value_type& top() noexcept
	{
		return top_->data;
	}
	bool empty() const noexcept
	{
        return top_==nullptr;
	}
	std::size_t size() const noexcept
	{
        if(top_ == nullptr) return 0ull;

        std::size_t k = 1;
        node* it = top_;
        while(1)
        {
            if(it->next !=nullptr)
            {
                it = it->next;
                ++k;
            }
            else return k;
        }
	}
	void push(const value_type& arg)
	{
        if(top_!=nullptr)
        {
            node* t = new node(arg);
            t->next = top_;
            top_ = t;
            return;
        }
        top_ = new node(arg);
	}
	void pop()
	{
        if(size() == 0)
        {
            return;
        }
        if(size() == 1)
        {
            delete top_;
            top_ = nullptr;
            return;
        }
        node* temp = top_->next;
        delete top_;
        top_ = temp;
        return;
	}

private:
	node* top_ = nullptr;
};

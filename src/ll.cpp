#include "ll.h"
#include <vector>
    namespace snakelinkedlist {
        
        LinkedList::LinkedList() {    // Default constructor
            list_head_ = nullptr;
            length_ = 0;
        }
        
        LinkedList::LinkedList(const std::vector<SnakeBodySegment>& values) { // Initialize from vector
            list_head_ = nullptr;
            length_ = 0;
            if (values.size() == 0) return;
            for (int i = 0; i < values.size(); i++) {
                SnakeBodySegment current_val_ = values.at(i);
                this->push_back(current_val_);
            }
        }
        
        // Big 5
        LinkedList::LinkedList(const LinkedList& source) {  // Copy constructor
            Node* source_current = source.list_head_;
            while(source_current) {
                SnakeBodySegment hold = source_current -> value_;
                this -> push_back(hold);
                source_current = source_current -> next_;
            }
            length_ = source.length_;
        }
        
        LinkedList::LinkedList(LinkedList&& source) noexcept : list_head_(source.list_head_), length_(source.length_)// Move constructor
        {
            list_head_ = source.list_head_;
            length_ = source.length_;
        }
        
        LinkedList::~LinkedList() {                                       // Destructor
            clear();
        }
        
        LinkedList& LinkedList::operator=(const LinkedList& source){     // Copy assignment operator
            if (this != &source) {
                clear();
                Node* source_current = source.list_head_;
                while(source_current) {
                    SnakeBodySegment hold = source_current -> value_;
                    this -> push_back(hold);
                    source_current = source_current -> next_;
                }
                length_ = source.length_;
            }
            return *this;
        }
        
        
        LinkedList& LinkedList::operator=(LinkedList&& source) noexcept { // Move assignment operator
            if (this != &source) {
                delete list_head_;
                length_ = 0;
                list_head_ = source.list_head_;
                length_ = source.length_;
                source.list_head_ = nullptr;
                source.length_ = 0;
            }
            return *this;
        }
        
        
        // Modifiers
        void LinkedList::push_front(SnakeBodySegment value) { // Push value on front
            if (value == NULL) { return; }
            Node *new_node_ = new Node(value);
            new_node_ -> next_ = list_head_;
            list_head_ = new_node_;
            length_ = length_ + 1;
        }
        
        void LinkedList::push_back(SnakeBodySegment value){  // Push value on back
            if (value == NULL) { return; }
            Node *new_node_ = new Node(value);
            new_node_->next_ = nullptr;
            
            if (!list_head_) {
                list_head_ = new_node_;
                length_++;
            } else {
                Node *last_node_ = list_head_;
                while(last_node_ -> next_) {
                    last_node_ = last_node_ -> next_;
                }
                last_node_ -> next_ = new_node_;
                length_ ++;
            }
        }
        
        void LinkedList::pop_front(){                        // remove front element
            if (!list_head_) {
                return;
            }
            Node *temp = list_head_;
            list_head_ = list_head_ -> next_;
            delete temp;
            length_ = length_ - 1;
        }
        
        void LinkedList::pop_back() {                        // remove back element
            if (!list_head_) {
                return;
            }
            Node *remove_next_ = list_head_;
            while(remove_next_ -> next_) {
                remove_next_ = remove_next_ -> next_;
            }
            delete remove_next_;
            remove_next_ -> next_ = nullptr;
            length_ = length_ - 1;
        }
        
        void LinkedList::RemoveNth(int n){                   // remove the Nth emement from the front
            if (n >= length_ || 0 > n) { return; }
            Node *remove_ptr_ = list_head_;
            Node *prv_ptr_;
            while (n > 0) {
                prv_ptr_ = remove_ptr_;
                remove_ptr_ = remove_ptr_ -> next_;
                n--;
            }
            prv_ptr_ -> next_ = remove_ptr_ -> next_;
            delete remove_ptr_;
            length_ = length_ - 1;
        }
        
        void LinkedList::clear() {
            if (!list_head_) { return; }
            Node *current_ = list_head_;
            while(current_) {
                Node *follow_ = current_ -> next_;
                delete current_;
                current_ = follow_;
            }
            list_head_ = nullptr;
            length_ = 0;
        }
        
        // Accessors
        SnakeBodySegment LinkedList::front() const {                  // Access the front value
            if (this -> length_ == 0) {
                return NULL;
            }
            SnakeBodySegment result =  list_head_ -> value_;
            return result;
        }
        
        SnakeBodySegment LinkedList::back() const {                  // Access the back value
            if (this -> length_ == 0) {
                return NULL;
            }
            Node* last = list_head_;
            while (last -> next_) {
                last = last -> next_;
            }
            return last -> value_;
        }
        
        int LinkedList::size() const {                                // return number of elements
            return length_;
        }
        
        std::vector<SnakeBodySegment> LinkedList::GetVector() const { // return a vector of the values
            std::vector<SnakeBodySegment> result_vec_;
            Node* current_ = list_head_;
            while (current_ -> next_) {
                SnakeBodySegment item_ = current_ -> value_;
                result_vec_.push_back(item_);
            }
            return result_vec_;
        }
        
        bool LinkedList::empty() const {    // check if empty
            if (!list_head_) { return true;}
            return false;
        }
        
        std::ostream& operator<<(std::ostream& os, const LinkedList& list){
            Node *current = list.list_head_;
            while(current -> next_) {
                os << current -> value_ << ", ";
                current = current -> next_;
            }
            os << current -> value_;
            return os;
        }
        
        bool LinkedList::operator==(const LinkedList& rhs) const {
            Node* current = list_head_;
            Node* rhs_current = rhs.list_head_;
            while(current || rhs_current) {
                if (current -> value_ != rhs_current -> value_ || !current || !rhs_current) {
                    return false;
                }
                rhs_current = rhs_current -> next_;
                current = current -> next_;
            }
            return true;
        }
        
        // This can effiently be implemented outside the class
        bool operator!=(const LinkedList& lhs, const LinkedList& rhs){
            return !(lhs == rhs);
        }
        
    } // namespace snakelinkedlist


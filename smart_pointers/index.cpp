#include <basic.h>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "constructor\n";
    };
    ~Entity()
    {
        std::cout << "destructor\n";
    };
};

int main()
{

    {
        // std::unique_ptr<Entity> entity(new Entity());
        // std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        // std::unique_ptr<Entity> e0 = entity;
        std::shared_ptr<Entity> se0;
        
        // weak ptr can share a poiter but does no have anything the counter of smart ptr 
        std::weak_ptr<Entity> we0;

        {
            std::shared_ptr<Entity> share_entity = std::make_shared<Entity>();
            // se0 = share_entity;
            // we0 = share_entity;
        }

        // se0 will be destroied here. share ptr create a count of shares
    }
}
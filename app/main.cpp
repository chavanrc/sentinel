#include <iostream>
#include <sw/redis++/redis++.h>

int main() {
    sw::redis::SentinelOptions sentinel_opts;
    sentinel_opts.nodes = {
            {"sentinel-1", 26379},
            {"sentinel-2", 26379},
            {"sentinel-3", 26379},
    };
    sentinel_opts.connect_timeout = std::chrono::milliseconds(100);
    sentinel_opts.socket_timeout = std::chrono::milliseconds(100);

    auto redis_sentinel = std::make_shared<sw::redis::Sentinel>(sentinel_opts);
    // Connection options for Redis
    sw::redis::ConnectionOptions connection_opts;
    connection_opts.connect_timeout = std::chrono::milliseconds(100);
    connection_opts.socket_timeout = std::chrono::milliseconds(100);
    sw::redis::ConnectionPoolOptions pool_options;
    auto redis_master = std::make_shared<sw::redis::Redis>(redis_sentinel, "mymaster", sw::redis::Role::MASTER, connection_opts,
                                                           pool_options);

    try {
        // Set a key-value pair
        redis_master->set("key", "value");

        // Get the value of a key
        auto val = redis_master->get("key");
        if (val) {
            std::cout << "The value of 'key' is " << *val << std::endl;
        } else {
            std::cout << "'key' does not exist." << std::endl;
        }
    } catch (const sw::redis::Error &e) {
        std::cerr << "Redis error: " << e.what() << std::endl;
    }

    return 0;
}

use bevy::prelude::*;

fn main() {
    App::new()
    .add_systems(Startup, add_people)
    .add_systems(Update, (hello_world, greet_people))
    .run();

}

#[derive(Component)]
struct Person;

#[derive(Component)]
struct Name(String);


// Add people to the world at startup
fn add_people(mut commands: Commands) {
    commands.spawn((Person, Name("Elaina Proctor".to_string())));
    commands.spawn((Person, Name("Renzo Hume".to_string())));
    commands.spawn((Person, Name("Zayna Nieves".to_string())));
}

// A simple system that prints "hello world!" every frame
fn hello_world() {
    println!("hello world!");
}

fn greet_people(query: Query<&Name, With<Person>>) {
    for name in &query {
        println!("hello {}!", name.0);
    }
}

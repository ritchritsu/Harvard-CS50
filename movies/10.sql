SELECT name FROM people
JOIN directors ON directors.person_id = people.id
JOIN movies ON movies.id = directors.movie_id
JOIN ratings on movies.id = ratings.movie_id
WHERE ratings.rating >= 9;

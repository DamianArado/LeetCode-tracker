class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids = sorted(asteroids)
        current = mass
        for asteroid in asteroids:
            if current < asteroid: return False
            current += asteroid
        return True
class Graph:
    def __init__(self):
        # Definición del grafo con lugares y sus conexiones
        self.graph = {
            "Casa": ["Parque", "Cafetería"],  # Conexiones desde la Casa
            "Parque": ["Cine", "Biblioteca"],  # Conexiones desde el Parque
            "Cafetería": ["Parque", "Casa"],  # Conexiones desde la Cafetería
            "Biblioteca": ["Parque", "Gimnasio"],  # Conexiones desde la Biblioteca
            "Gimnasio": ["Biblioteca", "Cafetería"],  # Conexiones desde el Gimnasio
            "Cine": ["Restaurante"],  # Conexión desde el Cine
            "Restaurante": []  # Conexión desde el Restaurante
        }

    def DLS(self, start, goal, depth, max_depth, path=[]):
        # Búsqueda en profundidad limitada (DFS)
        if depth > max_depth:
            return None
        if start == goal:
            return path + [start]

        for neighbor in self.graph[start]:
            if neighbor not in path:
                new_path = path + [start]
                new_path = self.DLS(neighbor, goal, depth + 1, max_depth, new_path)
                if new_path:
                    return new_path
        return None

    def IDDFS(self, start, goal):
        # Búsqueda en profundidad iterativa (IDDFS)
        max_depth = 0
        while True:
            result = self.DLS(start, goal, 0, max_depth)
            if result:
                return result
            max_depth += 1

if __name__ == "__main__":
    graph = Graph()
    start_location = "Casa"  # Ubicación de inicio
    goal_location = "Gimnasio"  # Ubicación de destino

    path = graph.IDDFS(start_location, goal_location)

    if path:
        print("Camino encontrado:")
        for location in path:
            print(location)
    else:
        print(f"No se encontró un camino desde {start_location} a {goal_location}.")